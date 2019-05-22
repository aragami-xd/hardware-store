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


using namespace std;

//convert an array of name into pointer to an array of vectors, containing the "words" in the name of a product 
vector<string>* convertName(string productNameString[], int totalProduct)
{
	vector<string> *vectorName = new vector<string>[totalProduct];		//the pointer to the array
	for (int i=0; i<totalProduct; i++) {
		istringstream iss(productNameString[i]);			//splitting name into words 
		vector<string> result(istream_iterator<string>{iss}, istream_iterator<string>());
		vectorName[i] = result;
	}
	return vectorName;
}


//loadStringData
string *loadStringData(string *productStringData, string address)
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
int *loadIntData(int *productIntData, string address)
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
float *loadFloatData(float *productFloatData, string address)
{
	int *productIntData;
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
			cout << "Any custom result sorting? (y/n): ";	//ask user if they want to sort
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
				cout << "3. Screen " << endl;
				cout << "4. RAM size" << endl;

				cin >> inputString;
				istringstream iss(inputString);
				iss >> inputNumber;

				if (inputNumber == 2) {
					finalProduct = sort->priceSort();
				} else if (inputNumber == 3) {
					finalProduct = sort->sizeSort();
				}

				if (inputNumber > 0 && inputNumber < 4) {			//in case a retard put a number not in the range 
					rightInput = true;
				}
			}
		}
	}
	
	return finalProduct;
}


void display(vector<Product*> finalProduct) 
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
			istringstream iss (select);
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
	} else {
		cout << "No result" << endl;			//if there are no results
	}
}




//create laptop objects and set their's data 
void createLaptop(Laptop *laptop, int totalProduct, int totalLaptop, string productType[], string productBrand[], vector<string>* productName, string productNameString[], int productPrice[])
{
	int current = 0;
	for (int i=0; i<totalProduct; i++) {
		if (productType[i] == "laptop") {		//check the type. if it's a laptop, the initialize
			laptop[current].setName(productName[i]);
			laptop[current].setNameString(productNameString[i]);
			laptop[current].setBrand(productBrand[i]);
			laptop[current].setType(productType[i]);
			laptop[current].setPrice(productPrice[i]);
			laptop[current].setSpecs("core i5", 8, "mx150", 256, 0, 15.6, 1.9, 42);
			current++;
		}
	}
}




//create phone objects and set their's data 
void createPhone(Phone *phone, int totalProduct, int totalPhone, string productType[], string productBrand[], vector<string>* productName, string productNameString[], int productPrice[], float productSize[])
{
	int current = 0;
	int phoneCurrent = 0;
	for (int i=0; i<totalProduct; i++) {
		if (productType[i] == "phone") {		//check the type, if match, then create a new phone
			phone[current].setName(productName[i]);
			phone[current].setNameString(productNameString[i]);
			phone[current].setBrand(productBrand[i]);
			phone[current].setType(productType[i]);
			phone[current].setPrice(productPrice[i]);
			phone[current].setSpecs("snapdragon 855", 8, 128, productSize[phoneCurrent], {12.2, 15}, 8, 4000);
			current++;
			phoneCurrent++;
		}
	}
}

