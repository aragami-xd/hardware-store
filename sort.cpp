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
int Sort::sortType()
{
	bool rightNumber = false;
	string inputString;			//in case a retard enter a string in and crash the program
	int inputNumber;

	while (rightNumber == false) {			//getting the order of sorting 
		cout << "Sort order:" << endl;
		cout << "1. Highest to Lowest" << endl;
		cout << "2. Lowest to Highest" << endl;

		cin >> inputString;
		istringstream iss(inputString);
		iss >> inputNumber;

		if (inputNumber == 1 || inputNumber == 2) {
			rightNumber = true;
		}
	}
	return inputNumber;
}

//implement the sortScreen function
void Sort::sortScreen(int i, int m, int inputNumber)
{
	if (inputNumber == 1) {
		if (finalProduct[m]->getpSize() > finalProduct[i]->getpSize()) {		//sort from high to low
			swap(finalProduct[i], finalProduct[m]);
		}
	} else if (inputNumber == 2) {
		if (finalProduct[m]->getpSize() < finalProduct[i]->getpSize()) {		//sort from low to high 
			swap(finalProduct[i], finalProduct[m]);
		}	
	}	
}

//implement the sortRam function
void Sort::sortRam(int i, int m, int inputNumber)
{
	if (inputNumber == 1) {
		if (finalProduct[m]->getpRam() > finalProduct[i]->getpRam()) {		//sort from high to low
			swap(finalProduct[i], finalProduct[m]);
		}
	} else if (inputNumber == 2) {
		if (finalProduct[m]->getpRam() < finalProduct[i]->getpRam()) {		//sort from low to high 
			swap(finalProduct[i], finalProduct[m]);
		}	
	}	
}

//implement the sortStorage function
void Sort::sortStorage(int i, int m, int inputNumber)
{
	if (inputNumber == 1) {
		if (finalProduct[m]->getpStorage() > finalProduct[i]->getpStorage()) {		//sort from high to low
			swap(finalProduct[i], finalProduct[m]);
		}
	} else if (inputNumber == 2) {
		if (finalProduct[m]->getpStorage() < finalProduct[i]->getpStorage()) {		//sort from low to high 
			swap(finalProduct[i], finalProduct[m]);
		}	
	}	
}

//implement the sortBattery function
void Sort::sortBattery(int i, int m, int inputNumber)
{
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

//implement the sortPrice function
void Sort::sortPrice(int i, int m, int inputNumber)
{
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



//implement the sortBy function 
vector<Product*> Sort::sortBy(int inputNumber) {
	int order;
	if (inputNumber != 1) {
		order = sortType();
	}
	//vector<Product*> product;
	for (int i=0; i<finalProduct.size(); i++) {
		for (int m=i; m<finalProduct.size(); m++) {	
			if (inputNumber == 2) {
				sortPrice(i,m, order);
			} else if (inputNumber == 3) {
				sortScreen(i,m, order);
			} else if (inputNumber == 4) {
				sortRam(i,m, order);
			} else if (inputNumber == 5) {
				sortStorage(i,m, order);	
			} else if (inputNumber == 6) {
				sortBattery(i,m, order);
			}
		}
		//product.push_back(finalProduct[i]);
	}
	return finalProduct;
}

