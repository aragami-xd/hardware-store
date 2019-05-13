#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <iostream>

#include "search.h"
#include "product.h"
#include "laptop.h"
#include "phone.h"


using namespace std;

//convert an array of name into pointer to an array of vectors, containing the "words" in the name of a product 
vector<string>* convertName(string productNameString[], int totalProduct)
{
	vector<string> *vectorName = new vector<string>[totalProduct];		//the pointer to the array
	for (int i=0; i<totalProduct; i++) {
		istringstream iss(productNameString[i]);			//splitting name into words 
		vector<string> result(istream_iterator<string>{iss}, istream_iterator<string>());
		vectorName[i] = result;
	}
	return vectorName;
}



Product* productPointer(int totalProduct) 
{
	for (int i=0; i<totalProduct; i++) {
		
	}
}


//run a list of different search functions 
void searchFunction(Search *search, string productBrand[], string productType[])
{
	search->inputSearch();
	search->sortBrand(productBrand);
	search->sortType(productType);
	search->sortName();
	search->matchBrand();
	search->matchType();
	search->matchName();
	
	vector<Product*> finalProduct = search->finalResult();
	for (int i=0; i<finalProduct.size(); i++) {
		cout << i << ". " << finalProduct[i]->getBrand() << endl;
	}
}


//create laptop objects and set their's data 
void createLaptop(Product *laptop[], int totalProduct, int totalLaptop, string productType[], string productBrand[], vector<string>* productName)
{
	int currentLaptop = 0;
	for (int i=0; i<totalProduct; i++) {
		if (currentLaptop < totalLaptop) {
			if (productType[i] == "laptop") {		//check the type. if it's a laptop, the initialize
				laptop[currentLaptop] = new Laptop();
				laptop[currentLaptop]->setName(productName[i]);
				laptop[currentLaptop]->setBrand(productBrand[i]);
				laptop[currentLaptop]->setType(productType[i]);
				currentLaptop++;
			}
		}
	}
}



//create phone objects and set their's data 
void createPhone(Product *phone[], int totalProduct, int totalPhone, string productType[], string productBrand[], vector<string>* productName)
{
	int currentPhone = 0;
	for (int i=0; i<totalProduct; i++) {
		if (currentPhone < totalPhone) {
			if (productType[i] == "phone") {		//check the type, if match, then create a new phone
				phone[currentPhone] = new Phone();
				phone[currentPhone]->setName(productName[i]);
				phone[currentPhone]->setBrand(productBrand[i]);
				phone[currentPhone]->setType(productType[i]);
				currentPhone++;
			}
		}
	}
}