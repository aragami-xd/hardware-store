#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <iostream>

#include "search.h"
#include "product.h"
#include "laptop.h"
#include "phone.h"


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



//run a list of different search functions 
void searchFunction(Search *search, string productBrand[], string productType[])
{
	search->inputSearch();
	search->sortBrand(productBrand);
	search->sortType(productType);
	search->sortName();
	search->matchBrand();
	search->matchType();
	search->matchName();
	
	//get and print search result 
	cout << endl;
	cout << "Search Results: " << endl;
	vector<Product*> finalProduct = search->finalResult();
	if (finalProduct.size() != 0) {					//if there are results 
		for (int i=0; i<finalProduct.size(); i++) {
			cout << (i+1) << ". " << finalProduct[i]->getBrand() << " " << finalProduct[i]->getNameString() << " - Price: $" << finalProduct[i]->getPrice() << endl;
		}

		//selection menu: choose one product
		int select;
		bool rightNumber = false;
		cout << endl;
		while (rightNumber == false) {			//using a while loop to force user to input a suitable number. if not, do it again
			cout << "Choose a product (From 1 to " << finalProduct.size() << "): ";
			cin >> select;
			select--;		//number starts from 1, but index starts from 0
			if (select < finalProduct.size()) {		//if the right number was inputed 
				rightNumber = true;
			}
		}

		cout << endl;
		cout << finalProduct[select]->getBrand() << " " << finalProduct[select]->getNameString() << endl;		//print name, price, specs...
		cout << "Price: $" << finalProduct[select]->getPrice() << endl;
		finalProduct[select]->printSpecs();
	} else {
		cout << "No result" << endl;			//if there are no results
	}
}




//create laptop objects and set their's data 
void createLaptop(Laptop *laptop, int totalProduct, int totalLaptop, string productType[], string productBrand[], vector<string>* productName, string productNameString[], int productPrice[])
{
	int current = 0;
	for (int i=0; i<totalProduct; i++) {
		if (current < totalLaptop) {
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
}




//create phone objects and set their's data 
void createPhone(Phone *phone, int totalProduct, int totalPhone, string productType[], string productBrand[], vector<string>* productName, string productNameString[], int productPrice[])
{
	int current = 0;
	for (int i=0; i<totalProduct; i++) {
		if (current < totalPhone) {
			if (productType[i] == "phone") {		//check the type, if match, then create a new phone
				phone[current].setName(productName[i]);
				phone[current].setNameString(productNameString[i]);
				phone[current].setBrand(productBrand[i]);
				phone[current].setType(productType[i]);
				phone[current].setPrice(productPrice[i]);
				phone[current].setSpecs("snapdragon 855", 8, 128, 6.5, {12.2, 15}, 8, 4000);
				current++;
			}
		}
	}
}