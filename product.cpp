#include "product.h"
#include <string>

using namespace std;

//implement the default product constructor
Product::Product()
{
	id = idList;
	idList++;
}

/*
//implement the product (pName, pPrice, pQty, pDescription, pType, pBrand) constructor
Product::Product(string pName, float pPrice, int pQty, string pDescription, string pType, string pBrand)
{
	name = pName;
	price = pPrice;
	qty = pQty;
	description = pDescription;
	brand = pBrand;
}
*/

//implement thal product idList function
int Product::idList = 218686;				//if ask, this number is from random.org 

//implement the product setName function
void Product::setName(string pName)
{
	name = pName;
}

//implement the product getName function
string Product::getName()
{
	return name;
}

//implement the product setPrice function
void Product::setPrice(float pPrice)
{
	price = pPrice;
}

//implement the product getPrice function
float Product::getPrice()
{
	return price;
}

//implement the product setQty function
void Product::setQty(int pQty)
{
	qty = pQty;
}

//implement the product getQty function
int Product::getQty()
{
	return qty;
}

//implement the product setDescription function
void Product::setDescription(string pDescription)
{
	description = pDescription;
}

//implement the product getDescription function
string Product::getDescription()
{
	return description;
}

//implement the product setBrand function
void Product::setBrand(string pBrand)
{
	brand = pBrand;
}

//implement the product getBrand function
string Product::getBrand()
{
	return brand;
}

//implement the product getID function
int Product::getID()
{
	return id;
}

//implement the product setMatch function
void Product::setMatch(int score) {
	match += score;
}

//implement the product getMatch function
int Product::getMatch()
{
	return match;
}

//implement the product destructor
Product::~Product()
{
}