#include <string>
#include <vector>
#include <iostream>
#include "product.h"
#include "phone.h"

using namespace std;

//implement the default phone constructor
Phone::Phone()
{
}

//implement the phon (pCpu, pRam, pStorage, pSize, prCamera, pfCamera, pBattery) constructor
Phone::Phone(string pCpu, int pRam, int pStorage, float pSize, vector<float> prCamera, float pfCamera, int pBattery)
{
	cpu = pCpu;
	ram = pRam;
	size = pSize;
	storage = pStorage;
	for (int i=0; i<prCamera.size(); i++) {
		rCamera.push_back(prCamera[i]);
	}
	fCamera = pfCamera;
	battery = pBattery;
}

//implement the phone setSpecs function
void Phone::setSpecs(string pCpu, int pRam, int pStorage, float pSize, vector<float> prCamera, float pfCamera, int pBattery)
{
	cpu = pCpu;
	ram = pRam;
	size = pSize;
	storage = pStorage;
	for (int i=0; i<prCamera.size(); i++) {
		rCamera.push_back(prCamera[i]);
	}
	fCamera = pfCamera;
	battery = pBattery;
}


//implement the phone getCpu function
string Phone::getCpu()
{
	return cpu;
}

//implement the phone getRam function
int Phone::getRam()
{
	return ram;
}

//implement the phone getSize function
float Phone::getSize()
{
	return size;
}

//implement the phone getStorage function
int Phone::getStorage()
{
	return storage;
}

//implement the phone getrCamera function
vector<float> Phone::getrCamera()
{
	return rCamera;
}

//implement the phone getfCamera function
float Phone::getfCamera()
{
	return fCamera;
}

//implement the phone getBattery function
int Phone::getBattery()
{
	return battery;
}

//implement the phone printSpecs function
void Phone::printSpecs()
{
	cout << "Specifications" << endl;
	cout << "Processor: " << cpu << endl;
	cout << "RAM: " << ram << " gb" <<  endl;
	cout << "Storage capacity: " << storage << " gb" << endl;
	cout << "Screen size: " << size << " inches" << endl;
	if (rCamera.size() == 1) {				//printing out rear cameras in different scenarios: 1 camera, 0 camera or more than 1
		cout << "Rear facing camera: " << rCamera[0] << " megapixel" << endl;
	} else if (rCamera.size() == 0) {
		cout << "Rear facing camera: 0 megapixel" << endl;
	} else {
		cout << "Rear facing cameras:" << endl;
		for (int i=0; i<rCamera.size(); i++) {
			cout << "  Camera " << i+1 << ": " <<  rCamera[i] << " megapixel" << endl;
		}
	} 
	cout << "Front facing camera: " << fCamera << " megapixel" << endl;
	cout << "Battery: " << battery << " mAh" << endl;
}

//implement the phone destructor
Phone::~Phone()
{
}