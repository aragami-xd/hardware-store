#ifndef LAPTOP_H
#define LAPTOP_H

#include <string>
#include <vector>
#include "store.h"
#include "product.h"

using namespace std;

class Laptop : public Store
{
public:
	Laptop();

	vector<Product> loadingLaptop;
	int totalLaptop;
	Product *laptop;

	virtual void sort(int toalProduct, Product *product);		//this function will prompt the object to look for products of its kind from store object
	virtual void loadData();		//this function will convert vector into array then delete it, for better run-time performance
	~Laptop();

};

#endif