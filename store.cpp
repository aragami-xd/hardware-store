#include <string>
#include "product.h"
#include "store.h"

//implement the default store constructor
Store::Store()
{
	storeName = "[Store name]";
}

//implement the store (totalProduct, *product) function
Store::Store(string name, int noProduct)
{
	totalProduct = noProduct;
	storeName = noProduct;
}

//implement the sort function
void Store::sort(int totalProduct, Product *product) 
{
}

//implement the store loadData function
void Store::loadData()
{
}

//implement the store destructor
Store::~Store()
{
}