#ifndef PHONE_H
#define PHONE_H

#include <string>
#include <vector>
#include "store.h"
#include "product.h"

using namespace std;

class Phone : public Store
{
public:
	Phone();

	vector<Product> loadingPhone;
	int totalPhone;
	Product *phone;

	virtual void sort(int toalProduct, Product *product);
	virtual void loadData();
	~Phone();

};

#endif