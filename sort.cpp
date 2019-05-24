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


//implement the sort sortType function
int Sort::sortType(string type)
{
	bool rightNumber = false;
	string inputString;			//in case a retard enter a string in and crash the program
	int inputNumber;

	while (rightNumber == false) {			//getting the order of sorting 
		cout << "Sort " << type << " by:" << endl;
		cout << "1. Highest to Lowest" << endl;
		cout << "2. Lowest to Highest" << endl;

		cin >> inputString;
		inputNumber = stoi(inputString);

		if (inputNumber == 1 || inputNumber == 2) {
			rightNumber = true;
		}
	}
	return inputNumber;
}


//implement the sortBy function 
vector<Product*> Sort::sortBy(string typeOfSort) {
	int inputNumber = sortType(typeOfSort);
	vector<Product*> product;
	for (int i=0; i<finalProduct.size(); i++) {
		for (int m=i; m<finalProduct.size(); m++) {		
			if (typeOfSort == "screen size") {			//sort by screen size
				if (inputNumber == 1) {
					if (finalProduct[m]->getpSize() > finalProduct[i]->getpSize()) {		//sort from high to low
						swap(finalProduct[i], finalProduct[m]);
					}
				} else if (inputNumber == 2) {
					if (finalProduct[m]->getpSize() < finalProduct[i]->getpSize()) {		//sort from low to high 
						swap(finalProduct[i], finalProduct[m]);
					}	
				}
			} else if (typeOfSort == "price") {			//sort by price 
				if (inputNumber == 1) {
					if (finalProduct[m]->getPrice() > finalProduct[i]->getPrice()) {		//sort from high to low
						swap(finalProduct[i], finalProduct[m]);
					}
				} else if (inputNumber == 2) {
					if (finalProduct[m]->getPrice() < finalProduct[i]->getPrice()) {		//sort from low to high 
						swap(finalProduct[i], finalProduct[m]);
					}	
				}
			} else if (typeOfSort == "ram capacity") {			//sort by ram capacity
				if (inputNumber == 1) {
					if (finalProduct[m]->getpRam() > finalProduct[i]->getpRam()) {		//sort from high to low
						swap(finalProduct[i], finalProduct[m]);
					}
				} else if (inputNumber == 2) {
					if (finalProduct[m]->getpRam() < finalProduct[i]->getpRam()) {		//sort from low to high 
						swap(finalProduct[i], finalProduct[m]);
					}	
				}
			} else if (typeOfSort == "storage capacity") {			//sort by storage capacity
				if (inputNumber == 1) {
					if (finalProduct[m]->getpStorage() > finalProduct[i]->getpStorage()) {		//sort from high to low
						swap(finalProduct[i], finalProduct[m]);
					}
				} else if (inputNumber == 2) {
					if (finalProduct[m]->getpStorage() < finalProduct[i]->getpStorage()) {		//sort from low to high 
						swap(finalProduct[i], finalProduct[m]);
					}	
				}
			} else if (typeOfSort == "battery capacity") {			//sort by battery capacity 
				if (inputNumber == 1) {
					if (finalProduct[m]->getpBattery() > finalProduct[i]->getpBattery()) {		//sort from high to low
						swap(finalProduct[i], finalProduct[m]);
					}
				} else if (inputNumber == 2) {
					if (finalProduct[m]->getpBattery() < finalProduct[i]->getpBattery()) {		//sort from low to high 
						swap(finalProduct[i], finalProduct[m]);
					}	
				}
			}
		}
		product.push_back(finalProduct[i]);
	}
	return product;
}

