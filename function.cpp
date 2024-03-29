#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <iostream>
#include <fstream>

#include "search.h"
#include "product.h"
#include "laptop.h"
#include "phone.h"
#include "sort.h"
#include "buy.h"


using namespace std;

//convert an array of name into pointer to an array of vectors, containing the "words" in the name of a product 
vector<string>* convertName(string productNameString[], int totalProduct)
{
	vector<string> *vectorName = new vector<string>[totalProduct];		//the pointer to the array
	for (int i=0; i<totalProduct; i++) {
		istringstream iss(productNameString[i]);			//splitting name into words, used for name comparison 
		vector<string> result(istream_iterator<string>{iss}, istream_iterator<string>());
		vectorName[i] = result;
	}
	return vectorName;
}


//loadStringData
string *loadStringData(string *productStringData, string address)	//load txt data as string 
{
	ifstream dataTxt;
	dataTxt.open(address);
	while (dataTxt.is_open()) {
		int line = 0;
		string lineData;
		while (getline(dataTxt, lineData)) {		//WARNING: since getline() will get the whole line, a whitespace will cause serious trouble
			productStringData[line] = lineData;
			line++;
		}
		dataTxt.close();
	}
	return productStringData;
}


//loadIntData function
int *loadIntData(int *productIntData, string address)		//read txt data files as int 
{
	ifstream dataTxt;
	dataTxt.open(address);
	while (dataTxt.is_open()) {
		int line = 0;
		string lineData;
		while (getline(dataTxt, lineData)) {			//input as string so we'll have to convert it to int	
			productIntData[line] = stoi(lineData);
			line++;
		}
		dataTxt.close();
	}
	return productIntData;
}

//loadFloatData function
float *loadFloatData(float *productFloatData, string address)		//read txt file data as float 
{
	ifstream dataTxt;
	dataTxt.open(address);
	while (dataTxt.is_open()) {
		int line = 0;
		string lineData;
		while (getline(dataTxt, lineData)) {		
			productFloatData[line] = stof(lineData);
			line++;
		}
		dataTxt.close();
	}
	return productFloatData;
}

	



//run a list of different search functions 
vector<Product*> searchFunction(Search *search, string productBrand[], string productType[])
{
	search->inputSearch();
	search->sortBrand(productBrand);
	search->sortType(productType);
	search->sortName();
	search->matchBrand();
	search->matchType();
	search->matchName();

	vector<Product*> finalProduct = search->finalResult();
	return finalProduct;
}



//run a list of sort functions
vector<Product*> sortFunction(Sort *sort, vector<Product*> finalProduct) 
{
	bool rightInput = false;
	string enableSort;
	string inputString;				//get the input number, convert from string to int in case a retard put a string in
	int inputNumber;
	if (finalProduct.size() > 0) { 
		while (rightInput == false) {
			cout << "Any custom result sorting, default is by relevance? (y/n): ";	//ask user if they want to sort
			cin >> enableSort;
			if (enableSort == "y" || enableSort == "n") {
				rightInput = true;
			}
		}
		if (enableSort == "y") {
			rightInput = false;
			while (rightInput == false) {
				cout << "Choose a sorting method: " << endl;		//list of types of sorts
				cout << "1. Relevance" << endl;
				cout << "2. Price" << endl;
				cout << "3. Screen" << endl;
				cout << "4. RAM size" << endl;
				cout << "5. Storage capacity" << endl;
				cout << "6. Battery size" << endl;

				cin >> inputString;
				istringstream iss(inputString);		//in case garbage input 
				iss >> inputNumber;
				

				if (inputNumber > 0 && inputNumber < 7) {			//in case a retard put a number not in the range 
					rightInput = true;
				}
			}
			//call a function corresponding to the type of sort 
			finalProduct = sort->sortBy(inputNumber);
		}
	}
	
	return finalProduct;
}



//forward declaring addToCart function
void addToCart(vector<Product*> finalProduct, Buy *buy, int number);


//displaying the search result and the product itself
void display(vector<Product*> finalProduct, Buy *buy) 
{
	cout << endl;
	cout << "Search Results: " << endl;
	if (finalProduct.size() != 0) {					//if there are results 
		for (int i=0; i<finalProduct.size(); i++) {
			cout << (i+1) << ". " << finalProduct[i]->getBrand() << " " << finalProduct[i]->getNameString() << " - Price: $" << finalProduct[i]->getPrice() << endl;
		}

		//selection menu: choose one product
		string select;
		int number;
		bool rightInput = false;
		cout << endl;
		while (rightInput == false) {			//using a while loop to force user to input a suitable number. if not, do it again
			cout << "Choose a product (From 1 to " << finalProduct.size() << "): ";
			cin >> select;
			istringstream iss (select);		//garbage input 
			iss >> number;
			number--;			//number starts from 1, but index starts from 0
			if (number < finalProduct.size() && number >= 0) {		//if the right number was inputed 
				rightInput = true;
			}
		}

		//print out the selected product
		cout << endl;
		cout << finalProduct[number]->getBrand() << " " << finalProduct[number]->getNameString() << endl;		//print name, price, specs...
		cout << "Price: $" << finalProduct[number]->getPrice() << endl;
		finalProduct[number]->printSpecs();	

		//addToCart function
		addToCart(finalProduct, buy, number);

	} else {
		cout << "No result" << endl;			//if there are no results
	}
}


void buyFunction(Buy *buy);

//addToCart function, see if user want to add the item to cart or not
void addToCart(vector<Product*> finalProduct, Buy *buy, int number)
{	
	bool rightInput = false;
	//add to cart or not
	while (rightInput == false) {
		string addCart;
		string checkout;
		cout << endl;
		cout << "Add to cart? (y/n)" << endl;			//check if add to cart or not	
		cin >> addCart;

		if (addCart == "y") {				//if add to cart
			buy->setCart(finalProduct[number]);
			cout << "Product added. Proceed to checkout (1) or continue shopping (2)?" << endl;			//to checkout or not
			cin >> checkout;
			if (checkout == "1") {
				buyFunction(buy);
			} else if (checkout == "2") {
				display(finalProduct, buy);
			}
			

		} else if (addCart == "n") {			//if not add to cart, return to displaying search result
			display(finalProduct, buy);
		}

		if (addCart == "y" || addCart == "n") {			//input either y or n, exit the function 
			rightInput = true;	
		}
	}
}

//buyFunction
void buyFunction(Buy *buy) 
{
	vector<Product*> cart = buy->getCart();

	cout << endl;
	cout << "Cart: " << endl;			//print out the cart 
	for (int i=0; i<cart.size(); i++) {
		cout << cart[i]->getNameString() << endl;
	}

	cout << "Total price: $" << buy->getCost() << endl;
	cout << "Shipping: $" << buy->getCost() * 0.1 << endl;	

	//get customer details
	cout << endl;
	string fName;
	cout << "Enter your first name: ";
	cin >> fName;
	buy->setfName(fName);

	string lName;
	cout << "Enter your last name: ";
	cin >> lName;
	buy->setlName(lName);

	string address;
	cout << "Enter address here: ";
	getline(cin, address);
	buy->setAddress(address);
	cout << endl;

	string card;
	cout << "Enter credit card here: ";
	cin >> card;
	buy->setCreditCard(card);

	string cvvInput;
	int cvv;
	cout << "Enter CVV number here (the 3 digits behind your card): ";
	cin >> cvvInput;
	istringstream iss(cvvInput);		//in case garbage input 
	iss >> cvv;
	buy->setCVV(cvv);

	//summary
	cout << endl;
	cout << "Name: " << buy->getfName() << " " << buy->getlName() << endl;
	cout << "Address: " << buy->getAddress() << endl;
	cout << "Credit card: " << buy->getCreditCard() << endl;

	bool rightInput = false;
	while (rightInput == false) {
		string purchase;
		cout << "Purchase? (y/n) " << endl;
		cin >> purchase;
		if (purchase == "y") {
			cout << "Processing your purchasement..." << endl;
			cout << "Thank you for your purchasement!" << endl;
		} else if (purchase == "n") {
			cout << "..." << endl;
		}
		if (purchase == "y" || purchase == "n") {
			rightInput = true;
		}
	}	

}









//create laptop objects and set their's data 
void createLaptop(Laptop *laptop, int totalProduct, int totalLaptop, string productType[], string productBrand[], 
	vector<string>* productName, string productNameString[], int productPrice[], string productCpu[], int productRam[],
	string productGpu[], float productSize[], int productSsd[], int productHdd[], float productWeight[], int productBattery[])
{
	int current = 0;
	for (int i=0; i<totalProduct; i++) {
		if (productType[i] == "laptop") {		//check the type. if it's a laptop, the initialize
			laptop[current].setName(productName[i]);
			laptop[current].setNameString(productNameString[i]);
			laptop[current].setBrand(productBrand[i]);
			laptop[current].setType(productType[i]);
			laptop[current].setPrice(productPrice[i]);
			laptop[current].setSpecs(productCpu[current], productRam[current], productGpu[current], productSsd[current], productHdd[current], productSize[current], productWeight[current], productBattery[current]);
			current++;
		}
	}
}




//create phone objects and set their's data 
void createPhone(Phone *phone, int totalProduct, int totalPhone, string productType[], string productBrand[],
	vector<string>* productName, string productNameString[], int productPrice[], string productProcessor[], int productRam[],
	float productSize[], int productStorage[], float productrCamera[], float productfCamera[], int productBattery[])
{
	int current = 0;
	for (int i=0; i<totalProduct; i++) {
		if (productType[i] == "phone") {		//check the type, if match, then create a new phone
			phone[current].setName(productName[i]);
			phone[current].setNameString(productNameString[i]);
			phone[current].setBrand(productBrand[i]);
			phone[current].setType(productType[i]);
			phone[current].setPrice(productPrice[i]);
			phone[current].setSpecs(productProcessor[current], productRam[current], productStorage[current], productSize[current], productrCamera[current], productfCamera[current], productBattery[current]);
			current++;
		}
	}
}






