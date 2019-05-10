#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;


class Product
{
public:
	Product();
	//Product(string pName, float pPrice, int pQty, string pDescription, string pType, string pBrand);

	string name;
	float price;
	int qty;
	string description;
	string brand;

	int id;
	static int idList;		

	int match;			//this variable will store the score of how match the object is to the search result 			

	void setName(string pName);
	string getName();
	void setPrice(float pPrice);
	float getPrice();
	void setQty(int pQty);
	int getQty();	
	void setDescription(string pDescription);
	string getDescription();
	void setBrand(string pBrand);
	string getBrand();

	int getID();

	void setMatch(int score);			//this function will add the score to "match" when searching
	int getMatch();			


	//virtual void setSpecs() =0;				//abstract method used to record data into specs 
	//virtual specs* getSpecs() =0;		//abstract method used to retrieve data from specs 	
	virtual void printSpecs() =0;
	

	~Product();

};



#endif


