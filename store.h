#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
#include "product.h"

using namespace std;


class Store : public Product
{
public:
	Store();
	Store(string name, int noProduct);

	int totalProduct;			//total amount of product that the store contain (not the qty of products, just how many products)
	string storeName;		


	virtual void sort(int totalProduct, Product *product);		//this function will prompt its subclasses to look for their data
	virtual void loadData();		//this function will tell all of it's subclases to 'convert' data in vector to array
	
	~Store();
};

#endif