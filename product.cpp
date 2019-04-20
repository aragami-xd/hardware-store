#include "product.h"
#include <string>

using namespace std;

//implement the default product constructor
Product::Product()
{
	name = "[Insert a name here]";
	price = 399;
	qty = 1;
	description = "[Insert a description here]";
	productType = "laptop";
}

//implement the product (pName, pPrice, pQty, pDescription, pType) constructor
Product::Product(string pName, float pPrice, int pQty, string pDescription, string pType)
{
	name = pName;
	price = pPrice;
	qty = pQty;
	description = pDescription;
	productType = pType;
}


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

//implement the product setProductType fucntion
void Product::setProductType(string pType)
{
	productType = pType;
}

//implement the product getProductType function
string Product::getProductType()
{
	return productType;
}


//implement the product destructor
Product::~Product()
{
}