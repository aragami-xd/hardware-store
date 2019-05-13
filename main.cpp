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
extern void searchFunction(Search *search, string productBrand[], string productType[]);
extern void createLaptop(Product *laptop[], int totalProduct, int totalLaptop, string productType[], string productBrand[], vector<string>* productName, string productNameString[]);
extern void createPhone(Product *phone[], int totalProduct, int totalPhone, string productType[], string productBrand[], vector<string>* productName, string productNameString[]);
//extern Product* productPointer(int totalProduct);


int main()
{
	//remember to re-record these variables
	int totalProduct = 6;
	int totalLaptop = 2;
	int totalPhone = 4;

	//initialize products 
	Product *laptop[totalLaptop];
	Product *phone[totalPhone];

	//initialize the array of products (testing purpose only) 
	string productType[totalProduct] = {"laptop", "phone", "phone", "laptop", "phone", "phone"};
	string productBrand[totalProduct] = {"asus", "samsung", "lg", "dell", "huawei", "samsung"};
	string productNameString[totalProduct] = {"zenbook 13", "galaxy s10", "g8 thinq", "xps 13", "p30 pro", "galaxy s10 plus"};
	vector<string>* productName = convertName(productNameString, totalProduct);		//convert name into names w/out space


	//initialize the laptops (and set brand, name)
	createLaptop(laptop, totalProduct, totalLaptop, productType, productBrand, productName, productNameString);


	//initialize the phones (and set brand, name)
	createPhone(phone, totalProduct, totalPhone, productType, productBrand, productName, productNameString);

	//hold the pointer to all the products
	vector<Product*> allProduct;
	//initialize the vector of all products 
	for (int i=0; i<totalLaptop; i++) {
		allProduct.push_back(laptop[i]);
	} 
	for (int i=0; i<totalPhone; i++) {
		allProduct.push_back(phone[i]);
	}


	//initialize search
	Search *search = new Search(totalProduct, allProduct);
	//search functions
	searchFunction(search, productBrand, productType);





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
