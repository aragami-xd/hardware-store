#ifndef SORT_H
#define SORT_H

#include <string>
#include <vector>
#include <iostream>

#include "product.h"

using namespace std;

class Sort
{
private: 
	vector<Product*> finalProduct;

public: 
	Sort();
	Sort(vector<Product*> product);

	int sortType(string type);
	vector<Product*> sortBy(string typeOfSort);


	~Sort();
};

#endif