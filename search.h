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
	Search(int totalProduct, vector<Product*> product);

	int totalProduct;
	vector<string> keywords;

	vector<string> name;
	string brand;
	string type;

	vector<Product*> allProduct;

	int scoreBrand;			//storing the "score" of matching data (e.g matching type = 50 points, matching type = 20 points)
	int scoreType;
	int scoreName;
	int productShown;		//how many products will be shown 

	void inputSearch();			//input the search "sentence" from the keyboard and split to words
	vector<string> getAllData(string productData[]);			//remove duplicate from dataset 

	void sortBrand(string inputBrand[]);		//check if there are any brand in the keyword
	void sortType(string inputType[]);		//check if there are any type in the keyword
	void sortName();				//the rest of the data will be name 

	void matchBrand();
	void matchType();
	void matchName();
	
	vector<Product*> finalResult();

	~Search();
};

#endif