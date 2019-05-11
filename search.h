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
	Search(int totalProduct);

	int totalProduct;
	vector<string> keywords;

	vector<string> name;
	string brand;
	string type;

	int scoreBrand;
	int scoreType;
	int scoreName;

	void inputSearch();			//input the search "sentence" from the keyboard and split to words
	vector<string> getAllData(string productData[]);			//remove duplicate from dataset 

	void sortBrand(string inputBrand[]);		//check if there are any brand in the keyword
	void sortType(string inputType[]);		//check if there are any type in the keyword
	void sortName();				//the rest of the data will be name 

	void matchBrand(vector<Product*> allProduct);
	void matchType(vector<Product*> allProduct);
	

	~Search();
};

#endif