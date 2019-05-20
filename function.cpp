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


//loadType function
string *loadType(string *productType)
{
	ifstream typeTxt;
	typeTxt.open("data/type.txt");
	while (typeTxt.is_open()) {
		int line = 0;
		string lineType;
		while (getline(typeTxt, lineType)) {		//WARNING: since getline() will get the whole line, a whitespace will cause serious trouble
			productType[line] = lineType;
			line++;
		}
		typeTxt.close();
	}
	return productType;
}


//loadNameString function
string *loadNameString(string *productNameString)
{
	ifstream nameTxt;
	nameTxt.open("data/name.txt");
	while (nameTxt.is_open()) {
		int line = 0;
		string lineName;
		while (getline(nameTxt, lineName)) {		
			productNameString[line] = lineName;
			line++;
		}
		nameTxt.close();
	}
	return productNameString;
}


//loadPrice function
int *loadPrice(int *productPrice)
{
	ifstream priceTxt;
	priceTxt.open("data/price.txt");
	while (priceTxt.is_open()) {
		int line = 0;
		string linePrice;
		while (getline(priceTxt, linePrice)) {		
			istringstream iss(linePrice);	
			iss >> productPrice[line];
			line++;
		}
		priceTxt.close();
	}
	return productPrice;
}


//loadBrand function
string *loadBrand(string *productBrand)
{
	ifstream brandTxt;
	brandTxt.open("data/brand.txt");
	while (brandTxt.is_open()) {
		int line = 0;
		string lineBrand;
		while (getline(brandTxt, lineBrand)) {		
			productBrand[line] = lineBrand;
			line++;
		}
		brandTxt.close();
	}
	return productBrand;
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
	bool rightNumber = false;
	string inputString;				//get the input number, convert from string to int in case a retard put a string in
	int inputNumber;

	while (rightNumber == false) {
		cout << "Choose a sorting method: " << endl;
		cout << "1. Relevance" << endl;
		cout << "2. Price" << endl;
		cout << "3. Screen " << endl;

		cin >> inputString;
		istringstream iss(inputString);
		iss >> inputNumber;

		if (inputNumber == 2) {
			finalProduct = sort->priceSort();
		}

		if (inputNumber > 0 && inputNumber < 4) {			//in case a retard put a number not in the range 
			rightNumber = true;
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
		bool rightNumber = false;
		cout << endl;
		while (rightNumber == false) {			//using a while loop to force user to input a suitable number. if not, do it again
			cout << "Choose a product (From 1 to " << finalProduct.size() << "): ";
			cin >> select;
			istringstream iss (select);
			iss >> number;
			number--;			//number starts from 1, but index starts from 0
			if (number < finalProduct.size() && number >= 0) {		//if the right number was inputed 
				rightNumber = true;
			}
		}

		//print out the selected product
		cout << endl;
		cout << finalProduct[number]->getBrand() << " " << finalProduct[number]->getNameString() << endl;		//print name, price, specs...
		cout << "Price: $" << finalProduct[number]->getPrice() << endl;
		//finalProduct[number]->printSpecs();
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