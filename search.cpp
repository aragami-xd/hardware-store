#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

#include "search.h"
#include "store.h"
#include "product.h"

using namespace std;

//implement the default search constructor
Search::Search()
{
}

//implement the search (store) constructor
Search::Search(Store store)
{
	*searchStore = store;
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

//implement void sortBrand function
void Search::sortBrand()
{
	for (int i=0; i<keywords.size(); i++) {					//check if any keyword match any brand name
		for (int m=0; m<searchStore->totalBrand; m++) {
			if (keywords[i] == searchStore->brand[m]) {
				brand = keywords[i];
			}
		}
	}
}

//implement the search destructor
Search::~Search()
{
}