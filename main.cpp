#include <iostream>
#include <string>
#include <vector> 
#include <sstream>
#include <iterator> 
#include <fstream>

#include "product.h"
#include "search.h"
#include "laptop.h"
#include "phone.h"
#include "sort.h"

using namespace std;

extern string* loadStringData(string *productData, string address);
extern int* loadIntData(int *productData, string address);
extern float* loadFloatData(float *productData, string address);
extern vector<string>* convertName(string productNameString[], int totalProduct);
extern int* loadPrice(int *productPrice);

extern void createLaptop(Laptop *laptop, int totalProduct, int totalLaptop, string productType[], string productBrand[], vector<string>* productName, string productNameString[], int productPrice[], string productCpu[], int productRam[], string productGpu[], float productSize[], int productSsd[], int productHdd[], float productWeight[], int productBattery[]);
extern void createPhone(Phone *phone, int totalProduct, int totalPhone, string productType[], string productBrand[], vector<string>* productName, string productNameString[], int productPrice[], string productProcessor[], int productRam[], float productSize[], int productStorage[], float productfCamera[], int productBattery[]);

extern vector<Product*> searchFunction(Search *search, string productBrand[], string productType[]);
extern vector<Product*> sortFunction(Sort *sort, vector<Product*> finalProduct);
extern void display(vector<Product*> finalProduct);

int main()
{
	//remember to re-record these variables
	int totalProduct = 32;
	int totalLaptop = 18;
	int totalPhone = 14;

	//initialize products 
	Laptop *laptop = new Laptop[totalLaptop];
	Phone *phone = new Phone[totalPhone];



	//general data
	//type
	string *productType = new string[totalProduct];
	productType = loadStringData(productType, "data/type.txt");
	//brand
	string *productBrand = new string[totalProduct];
	productBrand = loadStringData(productBrand, "data/brand.txt");
	//name
	string *productNameString = new string[totalProduct];
	productNameString = loadStringData(productNameString, "data/name.txt");
	vector<string>* productName = convertName(productNameString, totalProduct);		//convert name into names w/out space
	//price
	int *productPrice = new int[totalProduct];
	productPrice = loadIntData(productPrice, "data/price.txt");

	//phone dataset
	//phone processor
	string *phoneProcessor = new string[totalPhone];
	phoneProcessor = loadStringData(phoneProcessor, "data/phone processor.txt");
	//phone ram
	int *phoneRam = new int[totalPhone];
	phoneRam = loadIntData(phoneRam, "data/phone ram.txt");
	//phone screen size
	float *phoneSize = new float[totalPhone];
	phoneSize = loadFloatData(phoneSize, "data/phone screen.txt");
	//phone storage
	int *phoneStorage = new int[totalPhone];
	phoneStorage = loadIntData(phoneStorage, "data/phone storage.txt");
	//phone front camera
	float *phonefCamera = new float[totalPhone];
	phonefCamera = loadFloatData(phonefCamera, "data/phone front camera.txt");
	//phone battery 
	int *phoneBattery = new int[totalPhone];
	phoneBattery = loadIntData(phoneBattery, "data/phone battery.txt");

	//laptop
	//cpu
	string *laptopCpu = new string[totalLaptop];
	laptopCpu = loadStringData(laptopCpu, "data/laptop cpu.txt");
	//ram
	int *laptopRam = new int[totalLaptop];
	laptopRam = loadIntData(laptopRam, "data/laptop ram.txt");
	//gpu
	string *laptopGpu = new string[totalLaptop];
	laptopGpu = loadStringData(laptopGpu, "data/laptop gpu.txt");
	//size
	float *laptopSize = new float[totalLaptop];
	laptopSize = loadFloatData(laptopSize, "data/laptop screen.txt");
	//ssd (aka storage)
	int *laptopSsd = new int[totalLaptop];
	laptopSsd = loadIntData(laptopSsd, "data/laptop ssd.txt");
	//hdd
	int *laptopHdd = new int[totalLaptop];
	laptopHdd = loadIntData(laptopHdd, "data/laptop hdd.txt");
	//weight
	float *laptopWeight = new float[totalLaptop];
	laptopWeight = loadFloatData(laptopWeight, "data/laptop weight.txt");
	//battery 
	int *laptopBattery = new int[totalLaptop];
	laptopBattery = loadIntData(laptopBattery, "data/laptop battery.txt");


	


	//initialize the laptops (and set brand, name)
	createLaptop(laptop, totalProduct, totalLaptop, productType, productBrand, productName, productNameString, productPrice, laptopCpu, laptopRam, laptopGpu, laptopSize, laptopSsd, laptopHdd, laptopWeight, laptopBattery);

	//initialize the phones (and set brand, name)
	createPhone(phone, totalProduct, totalPhone, productType, productBrand, productName, productNameString, productPrice, phoneProcessor, phoneRam, phoneSize, phoneStorage, phonefCamera, phoneBattery);



	//hold the pointer to all the products
	vector<Product*> allProduct;
	//initialize the vector of all products 
	
	for (int i=0; i<totalLaptop; i++) {
		allProduct.push_back(laptop + i);
	} 
	for (int i=0; i<totalPhone; i++) {
		allProduct.push_back(phone + i);
	}
	




	//initialize search and sort
	Search *search = new Search(totalProduct, allProduct);
	Sort *sort;
	//search and sort functions
	vector<Product*> finalProduct = searchFunction(search, productBrand, productType);
	sort = new Sort(finalProduct);
	finalProduct = sortFunction(sort, finalProduct);
	display(finalProduct);




	//cleanup 
	delete search;
	delete[] laptop;
	delete[] phone;
	delete[] productNameString;
	delete[] productName;
	delete[] productBrand;
	delete[] productType;
	delete[] productPrice;
	delete[] phoneSize;
	delete[] phoneProcessor;
	delete[] phoneRam;
	delete[] phoneStorage;
	delete[] phonefCamera;
	delete[] phoneBattery;
	delete[] laptopCpu;
	delete[] laptopRam;
	delete[] laptopGpu;
	delete[] laptopSsd;
	delete[] laptopHdd;
	delete[] laptopSize;
	delete[] laptopWeight;
	delete[] laptopBattery;

	return 0;
}
