#include <string>
#include <vector>
#include <sstream>
#include <iterator>

#include "product.h"
#include "laptop.h"
#include "phone.h"


using namespace std;

//convert an array of name into pointer to an array of vectors, containing the "words" in the name of a product 
vector<string>* convertName(string productNameString[], int totalProduct)
{
	vector<string> *vectorName = new vector<string>[totalProduct];		//the pointer to the array
	for (int i=0; i<totalProduct; i++) {
		istringstream iss(productNameString[i]);			//splitting name into words 
		vector<string> result(istream_iterator<string>{iss}, istream_iterator<string>());
		vectorName[i] = result;
	}
	return vectorName;
}


Product* productPointer(int totalProduct) 
{
	for (int i=0; i<totalProduct; i++) {
		
	}
}
