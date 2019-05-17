#include <iostream>
#include <string>
#include <vector> 
#include <sstream>
#include <iterator> 
#include <fstream>
#include <sstream>

#include "product.h"
#include "search.h"
#include "laptop.h"
#include "phone.h"

using namespace std;

extern vector<string>* convertName(string productNameString[], int totalProduct);
extern void searchFunction(Search *search, string productBrand[], string productType[]);
extern void createLaptop(Laptop *laptop, int totalProduct, int totalLaptop, string productType[], string productBrand[], vector<string>* productName, string productNameString[], int productPrice[]);
extern void createPhone(Phone *phone, int totalProduct, int totalPhone, string productType[], string productBrand[], vector<string>* productName, string productNameString[], int productPrice[]);



int main()
{
	//remember to re-record these variables
	int totalProduct = 32;
	int totalLaptop = 18;
	int totalPhone = 14;

	//initialize products 
	Laptop *laptop = new Laptop[totalLaptop];
	Phone *phone = new Phone[totalPhone];

	//initialize the array of products' data 
	//type
	string productType[totalProduct];
	ifstream typeTxt;
	typeTxt.open("data/type.txt");
	while (typeTxt.is_open()) {
		int line = 0;
		string lineType;
		while (getline(typeTxt, lineType)) {		//WARNING: since getline() will get the whole line, a whitespace will cause serious trouble
			productType[line] = lineType;
			line++;
		}
		typeTxt.close();
	}

	//brand
	string productBrand[totalProduct];
	ifstream brandTxt;
	brandTxt.open("data/brand.txt");
	while (brandTxt.is_open()) {
		int line = 0;
		string lineBrand;
		while (getline(brandTxt, lineBrand)) {		
			productBrand[line] = lineBrand;
			line++;
		}
		brandTxt.close();
	}

	//name
	string productNameString[totalProduct];
	ifstream nameTxt;
	nameTxt.open("data/name.txt");
	while (nameTxt.is_open()) {
		int line = 0;
		string lineName;
		while (getline(nameTxt, lineName)) {		
			productNameString[line] = lineName;
			line++;
		}
		nameTxt.close();
	}
	vector<string>* productName = convertName(productNameString, totalProduct);		//convert name into names w/out space

	//price
	int productPrice[totalProduct];
	ifstream priceTxt;
	priceTxt.open("data/price.txt");
	while (priceTxt.is_open()) {
		int line = 0;
		string linePrice;
		while (getline(priceTxt, linePrice)) {		
			istringstream iss(linePrice);	
			iss >> productPrice[line];
			line++;
		}
		priceTxt.close();
	}
	




	//initialize the laptops (and set brand, name)
	createLaptop(laptop, totalProduct, totalLaptop, productType, productBrand, productName, productNameString, productPrice);


	//initialize the phones (and set brand, name)
	createPhone(phone, totalProduct, totalPhone, productType, productBrand, productName, productNameString, productPrice);

	//hold the pointer to all the products
	vector<Product*> allProduct;
	//initialize the vector of all products 
	
	for (int i=0; i<totalLaptop; i++) {
		allProduct.push_back(laptop + i);
	} 
	for (int i=0; i<totalPhone; i++) {
		allProduct.push_back(phone + i);
	}
	







	//initialize search
	Search *search = new Search(totalProduct, allProduct);
	//search functions
	searchFunction(search, productBrand, productType);





	//cleanup 
	delete search;
	delete[] laptop;
	delete[] phone;

	return 0;
}
