#include <iostream>
#include <string>
#include <vector> 
#include <sstream>
#include <iterator> 
#include <fstream>

#include "product.h"
#include "search.h"
#include "laptop.h"
#include "phone.h"

using namespace std;

extern vector<string>* convertName(string productNameString[], int totalProduct);
extern void searchFunction(Search *search, string productBrand[], string productType[]);
extern void createLaptop(Laptop *laptop[], int totalProduct, int totalLaptop, string productType[], string productBrand[], vector<string>* productName, string productNameString[], int productPrice[]);
extern void createPhone(Phone *phone[], int totalProduct, int totalPhone, string productType[], string productBrand[], vector<string>* productName, string productNameString[], int productPrice[]);

//extern Product* productPointer(int totalProduct);


int main()
{
	//remember to re-record these variables
	int totalProduct = 7;
	int totalLaptop = 3;
	int totalPhone = 4;

	//initialize products 
	Laptop *laptop[totalLaptop];
	Phone *phone[totalPhone];


	ifstream typeTxt;
	typeTxt.open("data/type.txt");


	//initialize the array of products (testing purpose only) 
	string productType[totalProduct];
	string productBrand[totalProduct] = {"asus", "samsung", "lg", "dell", "huawei", "samsung", "hp"};
	string productNameString[totalProduct] = {"zenbook 13", "galaxy s10", "g8 thinq", "xps 13", "p30 pro", "galaxy s10 plus", "envy"};
	vector<string>* productName = convertName(productNameString, totalProduct);		//convert name into names w/out space
	int productPrice[totalProduct] = {1400, 1000, 1000, 1600, 1000, 1200, 1000};

	
	int line = 0;
	string lineType;
	while (typeTxt.is_open()) {
		while (getline(typeTxt, lineType)) {		//WARNING: since getline() will get the whole line, a whitespace will cause serious trouble
			productType[line] = lineType;
			cout << productType[line] << endl;
			line++;
		}
		typeTxt.close();
	}
	

	//initialize the laptops (and set brand, name)
	createLaptop(laptop, totalProduct, totalLaptop, productType, productBrand, productName, productNameString, productPrice);


	//initialize the phones (and set brand, name)
	createPhone(phone, totalProduct, totalPhone, productType, productBrand, productName, productNameString, productPrice);

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
