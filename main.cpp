#include <iostream>
#include <string>
#include <fstream>
#include "product.h"

using namespace std;


int main()
{
	Product *laptop[3];

	//loading product details into memory 
	for (int i=0; i<3; i++) {
		laptop[i] = new Product("Zenbook", 1400, 1, "A good laptop", "laptop");
	}

	for (int i=0; i<3; i++) {
		delete laptop[i];
	}
	return 0;
}