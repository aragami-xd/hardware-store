#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>


class Product
{
private: 
	std::vector<string> name;
	std::string nameString; 		//for display purpose only. functions will be run on name
	float price;
	std::string description;
	std::string brand;
	std::string type;

	int id;
	static int idList;		

	int match;			//this variable will store the score of how match the object is to the search result 	

public:
	Product();		

	void setName(std::vector<string> pName);			//name
	std::vector<string> getName();
	void setNameString(std::string pNameString);
	std::string getNameString();
	void setPrice(float pPrice);		//price
	float getPrice();	
	void setBrand(std::string pBrand);		//brand
	std::string getBrand();
	void setType(std::string pType);		//type
	std::string getType();

	int getID();

	void setMatch(int score);			//this function will add the score to "match" when searching
	int getMatch();			
	virtual void printSpecs() =0;

	//added in second release function. these functions will return a piece of the specs
	virtual float getpSize() =0;
	virtual int getpRam() =0;
	virtual int getpStorage() =0;
	virtual int getpBattery() =0;
	

	~Product();

};



#endif

