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
	associateType = 10;
	productShown = 5;
}

//implement the search (totalProduct) function
Search::Search(int noProduct, vector<Product*> product)
{
	scoreBrand = 20;
	scoreType = 50;
	scoreName = 10;
	associateType = 10;
	productShown = 5;
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
	if (!brand.empty()) {			//testing every product's brand with "brand"
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



//implement the search matchName function
void Search::matchName()
{
	if (name.size() != 0) {
		for (int i=0; i<totalProduct; i++) {
			bool associate = false;
			vector<string> pName = allProduct[i]->getName();		//get every product's name
			for (int m=0; m< pName.size(); m++) {			//compare it to every name 
				for (int n=0; n<name.size(); n++) {
					if (pName[m] == name[n]) {			//compare name
						allProduct[i]->setMatch(scoreName);			//add score if match name
						associate = true;		//having a name match means other product in same category will get score
					}
				}
			}

			if (associate == true) {		//if a product triggers a name match
			string pType = allProduct[i]->getType();		//add score to every product in the same category 
				for (int a=0; a<totalProduct; a++) {			
					if (allProduct[a]->getType() == pType) {
						allProduct[a]->setMatch(associateType);
					}
				}
			}

		}
	}
}



//implement the search finalResult function
vector<Product*> Search::finalResult()
{		
	vector<Product*> sortedProduct;
	for (int i=0; i<totalProduct; i++) {
		for (int m=i; m<totalProduct; m++) {		//basically sort the name by descending order 
			if (allProduct[m]->getMatch() > allProduct[i]->getMatch()) {
				swap(allProduct[i], allProduct[m]);
			}
		}
		sortedProduct.push_back(allProduct[i]);
	}
	sortedProduct.erase(sortedProduct.begin() + productShown, sortedProduct.end());		//keep a few top result only 
	return sortedProduct;
}


//implement the search destructor
Search::~Search()
{
}