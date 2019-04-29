#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <vector>

#include "store.h"
#include "product.h"

using namespace std;

class Search : public Store
{
public:
	Search();
	Search(Store store);

	Store *searchStore;

	string phrase;
	vector<string> keywords;

	string name;
	string brand;
	string type;

	vector<string> inputSearch();

	void sortBrand();
	void sortType();

	~Search();
};

#endif