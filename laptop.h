#ifndef LAPTOP_H
#define LAPTOP_H

#include <string>
#include "product.h"

using namespace std;


class Laptop : public Product
{
private: 
	string cpu;
	int ram;
	string gpu;
	int ssd;
	int hdd;
	float size;
	float weight;	
	int battery;

	
public:
	Laptop();
	Laptop(string lCpu, int lRam, string lGpu, int lSsd, int lHdd, float lSize, float lWeight, int lBattery);


	void setSpecs(string lCpu, int lRam, string lGpu, int lSsd, int lHdd, float lSize, float lWeight, int lBattery);

	string getCpu();
	int getRam();
	string getGpu();
	int getSsd();
	int getHdd();
	float getSize();
	float getWeight();
	int getBattery();

	virtual void printSpecs();

	//second revision function
	float getpSize();
	int getpRam();
	int getpStorage();
	int getpBattery();


	~Laptop();
};

#endif
