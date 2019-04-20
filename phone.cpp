#include "phone.h"
#include "product.h"
#include <string>

using namespace std;

//implement the default phone constructor
Phone::Phone()
{
}

//implement the phone sort function
void Phone::sort(int totalProduct, Product *product)
{
	for (int i=0; i<totalProduct; i++) {
		if (product[i].getProductType() == "phone") {
			loadingPhone.push_back(product[i]);
		}
	}
}


//implement the virtual phone loadData function
void Phone::loadData()
{
	totalPhone = loadingPhone.size();
	phone = new Phone[totalPhone];
	for (int i=0; i<totalPhone; i++) {
		phone[i] = loadingPhone[i];
	}
	loadingPhone.clear();
}

//implement the phone destructor
Phone::~Phone()
{
}
