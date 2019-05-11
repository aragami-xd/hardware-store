#include <iostream>
#include <string>
#include <vector> 
#include <sstream>
#include <iterator> 

#include "product.h"
#include "search.h"
#include "laptop.h"
#include "phone.h"

using namespace std;

extern vector<string>* convertName(string productNameString[], int totalProduct);
//extern Product* productPointer(int totalProduct);

int main()
{
	int totalType = 2;			//this variable stores the total types of products in the store (e.g. laptop, phone...)
	int totalProduct = 5;
	int totalLaptop = 2;
	int totalPhone = 3;

	//initialize classes 
	Search *search = new Search(totalProduct);
	Product *laptop[totalLaptop];
	Product *phone[totalPhone];

	//initialize the array of products (testin purpose only) 
	string productType[totalProduct] = {"a", "b", "b", "a", "b"};
	string productBrand[totalProduct] = {"e", "f", "g", "e", "e"};
	string productNameString[totalProduct] = {"ab ade", "bc", "de", "ef", "tr"};
	vector<string>* productName;							//convert the name of products into strings w/out whitespace
	productName = convertName(productNameString, totalProduct);

	//initialize the laptops (and set brand, name)
	int currentLaptop = 0;
	for (int i=0; i<totalProduct; i++) {
		if (currentLaptop < totalLaptop) {
			if (productType[i] == "a") {		//check the type. if it's a laptop, the initialize
				laptop[currentLaptop] = new Laptop();
				//laptop[currentLaptop]->setName(productName[i]);
				laptop[currentLaptop]->setBrand(productBrand[i]);
				laptop[currentLaptop]->setType(productType[i]);
				currentLaptop++;
			}
		}
	}

	//initialize the phones (and set brand, name)
	int currentPhone = 0;
	for (int i=0; i<totalProduct; i++) {
		if (currentPhone < totalPhone) {
			if (productType[i] == "b") {
				phone[currentPhone] = new Phone();
				phone[currentPhone]->setBrand(productBrand[i]);
				phone[currentPhone]->setType(productType[i]);
				currentPhone++;
			}
		}
	}


	//initialize the vector of all products 
	vector<Product*> allProduct;
	for (int i=0; i<totalLaptop; i++) {
		allProduct.push_back(laptop[i]);
	} 
	for (int i=0; i<totalPhone; i++) {
		allProduct.push_back(phone[i]);
	}


	
	//search functions (testing purpose only)
	search->inputSearch();
	search->sortBrand(productBrand);
	search->sortType(productType);
	search->sortName();
	search->matchBrand(allProduct);
	search->matchType(allProduct);




	//cleanup 
	delete search;
	for (int i=0; i<totalLaptop; i++) {
		delete laptop[i];
	}
	for (int i=0; i<totalPhone; i++) {
		delete phone[i];
	}

	return 0;
}
