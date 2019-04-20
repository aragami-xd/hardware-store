#include "tv.h"
#include "product.h"
#include <string>

using namespace std;

//implement the default tv constructor
Tv::Tv()
{
}

//implement the tv sort function
void Tv::sort(int totalProduct, Product *product)
{
	for (int i=0; i<totalProduct; i++) {
		if (product[i].getProductType() == "tv") {
			loadingTv.push_back(product[i]);
		}
	}
}


//implement the virtual tv loadData function
void Tv::loadData()
{
	totalTv = loadingTv.size();
	tv = new Tv[totalTv];
	for (int i=0; i<totalTv; i++) {
		tv[i] = loadingTv[i];
	}
	loadingTv.clear();
}

//implement the tv destructor
Tv::~Tv()
{
}

