#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

using namespace std;


class Product
{
public:
	Product();

	vector<string> name;
	float price;
	int qty;
	string description;
	string brand;
	string type;

	int id;
	static int idList;		

	int match;			//this variable will store the score of how match the object is to the search result 			

	void setName(vector<string> pName);			//name
	vector<string> getName();
	void setPrice(float pPrice);		//price
	float getPrice();
	void setQty(int pQty);			//qty
	int getQty();	
	void setDescription(string pDescription);	//description
	string getDescription();
	void setBrand(string pBrand);		//brand
	string getBrand();
	void setType(string pType);		//type
	string getType();

	int getID();

	void setMatch(int score);			//this function will add the score to "match" when searching
	int getMatch();			


	//virtual void setSpecs() =0;				//abstract method used to record data into specs 
	//virtual specs* getSpecs() =0;		//abstract method used to retrieve data from specs 	
	virtual void printSpecs() =0;
	

	~Product();

};



#endif


