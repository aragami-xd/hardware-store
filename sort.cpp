#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

#include "sort.h"
#include "product.h"

using namespace std;

//implement the default sort constructor
Sort::Sort()
{
}

//implement the sort (product, noShown) constructor
Sort::Sort(vector<Product*> product)
{
	finalProduct = product;
}


//implement the sort priceSort function
vector<Product*> Sort::priceSort()
{
	bool rightNumber = false;
	string inputString;			//in case a retard enter a string in and crash the program
	int inputNumber;

	while (rightNumber == false) {
		cout << "Sort price by:" << endl;
		cout << "1. High to Low" << endl;
		cout << "2. Low to High" << endl;

		cin >> inputString;
		istringstream iss (inputString);
		iss >> inputNumber;

		if (inputNumber == 1 || inputNumber == 2) {
			rightNumber = true;
		}
	}

	vector<Product*> product;
	for (int i=0; i<finalProduct.size(); i++) {
		for (int m=i; m<finalProduct.size(); m++) {		
			if (inputNumber == 1) {
				if (finalProduct[m]->getPrice() > finalProduct[i]->getPrice()) {		//sort from high to low
					swap(finalProduct[i], finalProduct[m]);
				}
			} else if (inputNumber == 2) {
				if (finalProduct[m]->getPrice() < finalProduct[i]->getPrice()) {		//sort from low to high 
					swap(finalProduct[i], finalProduct[m]);
				}
			}
		}
		product.push_back(finalProduct[i]);
	}
	return product;
}

