#ifndef SORT_H
#define SORT_H

#include <string>
#include <vector>
#include <iostream>

#include "product.h"

class Sort
{
private: 
	std::vector<Product*> finalProduct;

public: 
	Sort();
	Sort(std::vector<Product*> product);

	void sortPrice(int i, int m, int order);
	void sortScreen(int i, int m, int order);
	void sortStorage(int i, int m, int order);
	void sortRam(int i, int m, int order);
	void sortBattery(int i, int m, int order);
	int sortType();			//general function that receives the input of which order of the sort the user wants to use 
	std::vector<Product*> sortBy(int inputNumber);			//which sorting method the user wants to use


	~Sort();
};

#endif