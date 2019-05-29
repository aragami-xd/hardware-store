#include "product.h"
#include <string>
#include <vector>

using namespace std;

//implement the default product constructor
Product::Product()
{
	id = idList;
	idList++;
}

//implement thal product idList function
int Product::idList = 218686;				//if ask, this number is from random.org 

//implement the product setName function
void Product::setName(std::vector<std::string> pName)
{
	name = pName;
}

//implement the product getName function
std::vector<std::string> Product::getName()
{
	return name;
}

//implement the product setNameString function
void Product::setNameString(std::string pNameString)
{
	nameString = pNameString;
}

//implement the product getNameString()
std::string Product::getNameString()
{
	return nameString;
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

//implement the product setBrand function
void Product::setBrand(std::string pBrand)
{
	brand = pBrand;
}

//implement the product getBrand function
std::string Product::getBrand()
{
	return brand;
}

//implement the product setType function 
void Product::setType(std::string pType)
{
	type = pType;
}

//implement the product getType function
std::string Product::getType()
{
	return type;
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