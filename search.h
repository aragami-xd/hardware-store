#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <vector>

#include "product.h"

using namespace std;

class Search 
{
public:
	Search();

	string phrase;
	vector<string> keywords;

	vector<string> name;
	string brand;
	string type;

	int scoreBrand;
	int scoreType;
	int scoreName;

	vector<string> inputSearch();			//input the search "sentence" from the keyboard and split to words
	void getKeyword(vector<string> result);				//save the search result to keywords
	vector<string> getAllData(string productData[], int totalProduct);			//remove duplicate from dataset 

	void sortBrand(string inputBrand[], int totalProduct);		//check if there are any brand in the keyword
	void sortType(string inputType[], int totalProduct);		//check if there are any type in the keyword
	void sortName(string inputName[]);				//the rest of the data will be name 

	void matchBrand(int totalProduct);
	void matchType(int totalProduct);
	

	~Search();
};

#endif