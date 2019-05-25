#ifndef LAPTOP_H
#define LAPTOP_H

#include <string>
#include "product.h"

class Laptop : public Product
{
private: 
	std::string cpu;
	int ram;
	std::string gpu;
	int ssd;
	int hdd;
	float size;
	float weight;	
	int battery;

	
public:
	Laptop();
	Laptop(std::string lCpu, int lRam, std::string lGpu, int lSsd, int lHdd, float lSize, float lWeight, int lBattery);


	void setSpecs(std::string lCpu, int lRam, std::string lGpu, int lSsd, int lHdd, float lSize, float lWeight, int lBattery);

	std::string getCpu();
	int getRam();
	std::string getGpu();
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
