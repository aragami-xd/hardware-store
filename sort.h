#ifndef SORT_H
#define SORT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Sort
{
private: 
	int productShown;
	vector<Product*> finalProduct;

public: 
	Sort();
	Sort(vector<Product*> product, int noShown);

	vector<Product*> removeItem();
	vector<Product*> priceSort();
	vector<Product*> sizeSort();
	vector<Product*> screenSort();
	vector<Product*> ramSort();

	~Sort();
}

#endif