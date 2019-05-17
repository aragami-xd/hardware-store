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

	string getcpu();
	int getram();
	string getgpu();
	int getssd();
	int gethdd();
	float getsize();
	float getweight();
	int getBattery();

	//void setSpecs(string lCpu, int lRam, string lGpu, int lSsd, int lHdd, float lSize, float lWeight);		//add data to specSheet 
	//specs *getSpecs();

	virtual void printSpecs();


	~Laptop();
};

#endif
