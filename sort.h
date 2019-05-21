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
	vector<Product*> priceSort();
	vector<Product*> sizeSort();
	//vector<Product*> ramSort();
	//vector<Product*> storageSort();
	//vector<Product*> batterySort();

	~Sort();
};

#endif