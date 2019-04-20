#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;


class Product
{
public:
	Product();
	Product(string pName, float pPrice, int pQty, string pDescription, string pType);

	string name;
	float price;
	int qty;
	string description;
	string productType;				//the main type of the product, like laptops, smartphones, desktops, cameras, etc.
	//string tags[];					//this will contain tag details. for eg: a laptop will have tags like ultrabook, gamingLaptop, 2in1, etc. a phone will have tags like flagship, budget, midRange, etc.
	string brand;	

	void setName(string pName);
	string getName();
	void setPrice(float pPrice);
	float getPrice();
	void setQty(int pQty);
	int getQty();	
	void setDescription(string pDescription);
	string getDescription();
	void setProductType(string pType);
	string getProductType();
	

	~Product();

};



#endif


