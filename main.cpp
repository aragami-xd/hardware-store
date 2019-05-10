#include <iostream>
#include <string>
#include <vector> 

#include "product.h"
#include "search.h"
#include "laptop.h"
#include "phone.h"
//extern void createLaptop(int totalProduct, int totalLaptop, string productType[], string productBrand[], string productName[]);

using namespace std;

int main()
{
	int totalType = 2;			//this variable stores the total types of products in the store (e.g. laptop, phone...)
	int totalProduct = 4;
	int totalLaptop = 2;

	//initialize classes 
	Search *search = new Search();

	//initialize the array of products 
	string productType[totalProduct] = {"a", "b", "c", "a"};
	string productBrand[totalProduct] = {"e", "f", "g", "e"};
	string productName[totalProduct] = {"ab", "bc", "de", "ef"};

	
	//search functions 
	search->getKeyword(search->inputSearch());
	search->sortBrand(productBrand, totalProduct);
	search->sortType(productType, totalProduct);
	search->sortName(productName);
	
	//Laptop *laptop = new Laptop();
	

	Laptop *laptop[totalLaptop];

	//initialize the laptops 
	int currentLaptop = 0;
	for (int i=0; i<totalProduct; i++) {
		if (currentLaptop < totalLaptop) {
			if (productType[i] == "a") {		//check the type. if it's a laptop, the initialize
				laptop[currentLaptop] = new Laptop();
				laptop[currentLaptop]->setName(productName[i]);
				laptop[currentLaptop]->setBrand(productBrand[i]);
				currentLaptop++;
			}
		}
	}
	laptop[1]->printSpecs();

	//"Snapdragon 855", 8, 128, 6.5, {12.2, 15, 18}, 8, 4100

	delete search;
	for (int i=0; i<totalLaptop; i++) {
		delete laptop[i];
	}

	return 0;
}
