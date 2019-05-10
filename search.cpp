#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

#include "search.h"
#include "product.h"

using namespace std;

//implement the default search constructor
Search::Search()
{
	scoreBrand = 20;
	scoreType = 50;
	scoreName = 10;
}

//implement the search inputSearch function
vector<string> Search::inputSearch()
{
	cout << "Enter a product here: " << endl;
	getline(cin, phrase);			//input the whole line of text as a string
	istringstream iss(phrase);					//convert a 'phrase' into separate 'words'
	vector<string> result(istream_iterator<string>{iss}, istream_iterator<string>());
	return result;
}



//implement the search getKeyword function
void Search::getKeyword(vector<string> result)
{
	keywords = result;
}




vector<string> Search::getAllData(string productData[], int totalProduct)			//this function will compile a list of different strings in an array 
{
	vector<string> dataList;			//store the type of all the products 
	bool add = true;
	for (int i=0; i<totalProduct; i++) {			//check every element in productData
		for (int m=0; m<dataList.size(); m++) {			//check every element in the existing vector 
			if (productData[i] == dataList[m]) {
				add = false;				//if there is a match, then add becomes false
			}
		}
		if (add == true) {				//add if there are no match 
			dataList.push_back(productData[i]);
		}
		add = true;			//reset the state of add 
	}
	return dataList;
}




//implement void sortBrand function
void Search::sortBrand(string inputBrand[], int totalProduct)
{
	vector<string> storeBrand = getAllData(inputBrand, totalProduct);
	for (int i=0; i<keywords.size(); i++) {					//check if any keyword match any brand name
		for (int m=0; m<storeBrand.size(); m++) {
			if (keywords[i] == storeBrand[m]) {
				brand = keywords[i];			//if identical, then that's the brand 
			}
		}
	}
	cout << "brand " << brand << endl;
}




//implement void sortType function
void Search::sortType(string inputType[], int totalProduct)
{
	vector<string> storeType = getAllData(inputType, totalProduct);
	for (int i=0; i<keywords.size(); i++) {					//check if any keyword match any type name
		for (int m=0; m<storeType.size(); m++) {
			if (keywords[i] == storeType[m]) {			//if identical, then that's the type 
				type = keywords[i];
			}
		}
	}
	cout << "type " << type << endl;
}


//implement the void sortName function
void Search::sortName(string inputName[])
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



//implement the void matchBrand function
void Search::matchBrand(int totalProduct)
{
	if (!brand.empty()) {
		for (int i=0; i<totalProduct; i++)	{
			/*if (......->getBrand() == brand) {
				....->setScore(scoreBrand);
			*/
		}
	}
}

//implement the void matchType function
void Search::matchType(int totalProduct)
{
	if (!type.empty()) {
		for (int i=0; i<totalProduct; i++) {
			
		}
	}
}

//implement the search destructor
Search::~Search()
{
}