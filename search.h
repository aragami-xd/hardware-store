#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <vector>

#include "product.h"

class Search 
{
private:

	int totalProduct;
	std::vector<std::string> keywords;

	std::vector<std::string> name;
	std::string brand;
	std::string type;

	std::vector<Product*> allProduct;

	int scoreBrand;			//storing the "score" of matching data (e.g matching type = 50 points, matching type = 20 points)
	int scoreType;
	int scoreName;
	int associateName;		//if matchName is called, every product in the same category or brand will also gain some points (normal search engine behavior)
	int productShown;		//how many products will be shown 

public:
	Search();
	Search(int totalProduct, std::vector<Product*> product);

	void inputSearch();			//input the search "sentence" from the keyboard and split to words
	std::vector<std::string> getAllData(std::string productData[]);			//remove duplicate from dataset 

	void sortBrand(std::string inputBrand[]);		//check if there are any brand in the keyword
	void sortType(std::string inputType[]);		//check if there are any type in the keyword
	void sortName();				//the rest of the data will be name 

	void matchBrand();		//check every item in allProduct and see what that product matches in the search phrase 
	void matchType();
	void matchName();
	
	std::vector<Product*> finalResult();		//keep a couple of items, remove the rest and return it 

	~Search();
};

#endif