#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

#include "sort.h"

using namespace std;

//implement the default sort constructor
Sort::Sort()
{
}

//implement the sort (product, noShown) constructor
Sort::Sort(vector<Product*> product, int noShown)
{
	finalProduct = product;
	productShown = noShown;
}

//implement the sort removeItem function
vector<Product*> removeItem()
{
	finalProduct.erase(finalProduct.begin() + productShown, finalProduct.end());
	return finalProduct;	
}

//implement the sort priceSort function
vector<Product*> priceSort()
{
	cout << "Sort price by:" << endl;
	cout << "1. High to Low" << endl;
	cout << "2. Low to High" << endl;
	cout << "Choose a sorting order (1 or 2): ";

	string inputString;			//in case a retard enter a string in and crash the program
	int inputNumber;
	cin >> inputString;
	istringstream iss (inputString);
	iss >> inputNumber;

	if (inputNumber == 1) {
		sort(finalProduct.begin(), finalProduct.end(), greater<int>());
	} else if (inputNumber == 2) {
		sort(finalProduct.being(), finalProduct.end());
	}
	return removeItem();
}

