#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>

#include "search.h"
#include "product.h"

using namespace std;

//implement the default search constructor
Search::Search()
{
	scoreBrand = 20;
	scoreType = 50;
	scoreName = 10;
	productShown = 2;
}

//implement the search (totalProduct) function
Search::Search(int noProduct, vector<Product*> product)
{
	scoreBrand = 20;
	scoreType = 50;
	scoreName = 10;
	productShown = 2;
	allProduct = product;
	totalProduct = noProduct;
}

//implement the search inputSearch function
void Search::inputSearch()
{
	string phrase;
	cout << "Enter a product here: " << endl;
	getline(cin, phrase);			//input the whole line of text as a string
	istringstream iss(phrase);					//convert a 'phrase' into separate 'words'
	vector<string> result(istream_iterator<string>{iss}, istream_iterator<string>());
	keywords = result;
}


//implement search sortBrand function
void Search::sortBrand(string inputBrand[])
{
	for (int i=0; i<keywords.size(); i++) {					//check if any keyword match any brand name
		for (int m=0; m<totalProduct; m++) {
			if (keywords[i] == inputBrand[m]) {
				brand = keywords[i];			//if identical, then that's the brand 
			}
		}
	}
	cout << "brand " << brand << endl;
}




//implement search sortType function
void Search::sortType(string inputType[])
{
	for (int i=0; i<keywords.size(); i++) {					//check if any keyword match any type name
		for (int m=0; m<totalProduct; m++) {
			if (keywords[i] == inputType[m]) {			//if identical, then that's the type 
				type = keywords[i];
			}
		}
	}
	cout << "type " << type << endl;
}


//implement the search sortName function
void Search::sortName()
{
	for (int i=0; i<keywords.size(); i++) {
		if (keywords[i] != brand && keywords[i] != type) {			//if it's not type or brand, then it's a name
			name.push_back(keywords[i]);
		}
	}
	for (int i=0; i<name.size(); i++) {
		cout << "name " << name[i] << endl;
	}
}



//implement the search matchBrand function
void Search::matchBrand()
{
	if (!brand.empty()) {
		for (int i=0; i<totalProduct; i++)	{
			if (allProduct[i]->getBrand() == brand) {
				allProduct[i]->setMatch(scoreBrand);
			}
		}
	}
}


//implement the search matchType function
void Search::matchType()
{
	if (!type.empty()) {
		for (int i=0; i<totalProduct; i++) {
			if (allProduct[i]->getType() == type) {
				allProduct[i]->setMatch(scoreType);
			}
		}
	}
}

//implement the search finalResult function
void Search::finalResult()
{		
	for (int i=0; i<totalProduct; i++) {
		for (int m=i; m<totalProduct; m++) {		//basically sort the name by descending order 
			if (allProduct[m]->getMatch() > allProduct[i]->getMatch()) {
				swap(allProduct[i], allProduct[m]);
			}
		}
		sortedProduct.push_back(allProduct[i]);
	}
	sortedProduct.erase(sortedProduct.begin() + productShown, sortedProduct.end());		//keep a few top result only 
}

//implement the search printResult function
void Search::printResult()
{
	for (int i=0; i<sortedProduct.size(); i++) {
		cout << i << ". " << sortedProduct[i]->getBrand() << endl;
	}
}


//implement the search destructor
Search::~Search()
{
}