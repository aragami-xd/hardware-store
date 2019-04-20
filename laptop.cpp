#include "laptop.h"
#include "product.h"
#include <string>

using namespace std;

//implement the default laptop constructor
Laptop::Laptop()
{
}

//implement the laptop sort function
void Laptop::sort(int totalProduct, Product *product)
{
	for (int i=0; i<totalProduct; i++) {
		if (product[i].getProductType() == "laptop") {
			loadingLaptop.push_back(product[i]);
		}
	}
}


//implement the virtual laptop loadData function
void Laptop::loadData()
{
	totalLaptop = loadingLaptop.size();
	laptop = new Laptop[totalLaptop];
	for (int i=0; i<totalLaptop; i++) {
		laptop[i] = loadingLaptop[i];
	}
	loadingLaptop.clear();
}

//implement the laptop destructor
Laptop::~Laptop()
{
}




