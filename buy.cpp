#include "buy.h"

using namespace std;

//implement the default buy constructor
Buy::Buy()
{
}

//implement the buy setCart function					//ah shit, here we go again...
void Buy::setCart(Product *newProduct)
{
	cart.push_back(newProduct);
	setCost(newProduct->getPrice());
}

//implement the buy getCart function	
vector<Product*> Buy::getCart()
{
	return cart;
}

//implement the setCost function
void Buy::setCost(int totalCost)
{
	cost += totalCost;
}

//implement the getCost function
int Buy::getCost()
{
	return cost;
}


//implement the buy setfName function
void Buy::setfName(string firstName)
{
	fName = firstName;
}

//implement the buy getfName function
string Buy::getfName()
{
	return fName;
}

//implement the buy setlName function
void Buy::setlName(string lastName)
{
	lName = lastName;
}

//implement the buy getlName function
string Buy::getlName()
{
	return lName;
}

//implement the buy setAddress function
void Buy::setAddress(string billingAddress)
{
	address = billingAddress;
}

//implement the buy getAddress function
string Buy::getAddress()
{
	return address;
}

//implement the buy setCreditCard function
void Buy::setCreditCard(string card)
{
	creditCard = card;
}

//implement the buy getCreditCard function
string Buy::getCreditCard()
{
	return creditCard;
}

//implement the buy setCVV function
void Buy::setCVV(int cvvNumber)
{
	cvv = cvvNumber;
}

//implement the buy getCVV function
int Buy::getCVV()
{
	return cvv;
}

//implement the buy destructor
Buy::~Buy()
{
}



