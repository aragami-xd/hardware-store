#ifndef BUY_H
#define BUY_H


#include "product.h"
#include <string>
#include <vector>

class Buy
{
private:
	std::vector<Product*> cart;
	int cost;
	std::string fName;
	std::string lName;
	std::string address;
	std::string creditCard;
	int cvv;

public:
	Buy();

	void setCart(Product *newProduct);			//oh shit, here we go again...
	std::vector<Product*> getCart();
	void setCost(int totalCost);
	int getCost();
	void setfName(std::string firstName);
	std::string getfName();
	void setlName(std::string lastName);
	std::string getlName();
	void setAddress(std::string billingAddress);
	std::string getAddress();
	void setCreditCard(std::string card);
	std::string getCreditCard();
	void setCVV(int cvvNumber);
	int getCVV();

	~Buy();
};

#endif