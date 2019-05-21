#include "laptop.h"
#include "product.h"
#include <string>
#include <iostream>

using namespace std;

//implement the default laptop constructor
Laptop::Laptop()
{
}



//implement the laptop (lCpu, lRam, lGpu, lSsd, lHdd, lSize, lWeight) constructor 
Laptop::Laptop(string lCpu, int lRam, string lGpu, int lSsd, int lHdd, float lSize, float lWeight, int lBattery)
{
	cpu = lCpu;
	ram = lRam;
	gpu = lGpu;
	ssd = lSsd;
	hdd = lHdd;
	size = lSize;
	weight = lWeight;
	battery = lBattery;
}

//implement the laptop setSpecs function
void Laptop::setSpecs(string lCpu, int lRam, string lGpu, int lSsd, int lHdd, float lSize, float lWeight, int lBattery)
{
	cpu = lCpu;
	ram = lRam;
	gpu = lGpu;
	ssd = lSsd;
	hdd = lHdd;
	size = lSize;
	weight = lWeight;
	battery = lBattery;
}


//implement the laptop getcpu function
string Laptop::getCpu()
{
	return cpu;
}


//implement the laptop getram function
int Laptop::getRam()
{
	return ram;
}

//implement the laptop getgpu function
string Laptop::getGpu()
{
	return gpu;
}

//implement the laptop getssd function
int Laptop::getSsd()
{
	return ssd;
}

//implement the laptop gethdd function
int Laptop::getHdd()
{
	return hdd;
}

//implement the laptop getsize function
float Laptop::getSize()
{
	return size;
}

//implement the laptop getweight function
float Laptop::getWeight()
{
	return weight;
}

//implement the laptop getBattery function
int Laptop::getBattery()
{
	return battery;
}

//implement the laptop printSpecs function
void Laptop::printSpecs()
{
	cout << "Specifications" << endl;
	cout << "Processor: " << cpu << endl;
	cout << "RAM: " << ram << " gb" << endl;
	cout << "Graphics Card: " << gpu << endl;
	cout << "Solid State Drive: " << ssd << " gb" << endl;
	cout << "Hard Disk Drive: " << hdd << " gb" << endl;
	cout << "Screen size: " << size << " inches" << endl;
	cout << "Weight: " << weight << " kg (" << (weight*2.2) << " lbs)" << endl;
	cout << "Battery: " << battery << " Wh" << endl;
}

//implement the laptop getpSize function
float Laptop::getpSize()
{
	return getSize();
}

//implement the laptop getpRam function
int Laptop::getpRam()
{
	return getRam();
}

//implement the laptop getpStorage function
int Laptop::getpStorage()
{
	return getSsd();
}

//implement the laptop getpBattery function
int Laptop::getpBattery()
{
	return getBattery();
}


//implement the laptop destructor
Laptop::~Laptop()
{
}




