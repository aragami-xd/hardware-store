#ifndef TV_H
#define TV_H

#include <string>
#include <vector>
#include "store.h"
#include "product.h"

using namespace std;

class Tv : public Store
{
public:
	Tv();

	vector<Product> loadingTv;
	int totalTv;
	Product *tv;

	virtual void sort(int toalProduct, Product *product);
	virtual void loadData();
	~Tv();

};

#endif