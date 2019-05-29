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
Phone::Phone(std::string pCpu, int pRam, int pStorage, float pSize, float prCamera, float pfCamera, int pBattery)
{
	cpu = pCpu;
	ram = pRam;
	size = pSize;
	storage = pStorage;
	rCamera = prCamera;
	fCamera = pfCamera;
	battery = pBattery;
}

//implement the phone setSpecs function
void Phone::setSpecs(std::string pCpu, int pRam, int pStorage, float pSize, float prCamera, float pfCamera, int pBattery)
{
	cpu = pCpu;
	ram = pRam;
	size = pSize;
	storage = pStorage;
	rCamera = prCamera;
	fCamera = pfCamera;
	battery = pBattery;
}


//implement the phone getCpu function
std::string Phone::getCpu()
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
float Phone::getrCamera()
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
	cout << "Rear facing camera: " << rCamera << " megapixel" << endl;
	cout << "Front facing camera: " << fCamera << " megapixel" << endl;
	cout << "Battery: " << battery << " mAh" << endl;
}


//implement the phone getpSize function
float Phone::getpSize()
{
	return getSize();
}

//implement the phone getpRam function
int Phone::getpRam()
{
	return getRam();
}

//implement the phone getpStorage function
int Phone::getpStorage()
{
	return getStorage();
}

//implement the phone getpBattery function
int Phone::getpBattery()
{
	return getBattery();
}


//implement the phone destructor
Phone::~Phone()
{
}