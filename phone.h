#ifndef PHONE_H
#define PHONE_H

#include <string>
#include <vector>
#include "product.h"

class Phone : public Product 
{
private:
	std::string cpu;		//basically specs
	int ram;
	float size;
	int storage;
	float rCamera;			
	float fCamera;
	int battery;
	
public: 
	Phone();
	Phone(std::string pCpu, int pRam, int pStorage, float pSize, float prCamera, float pfCamera, int pBattery);

	void setSpecs(std::string pCpu, int pRam, int pStorage, float pSize, float prCamera, float pfCamera, int pBattery);

	std::string getCpu();
	int getRam();
	float getSize();
	int getStorage();
	float getrCamera();
	float getfCamera();
	int getBattery();

	virtual void printSpecs();

	//second revision
	float getpSize();		//for product pure virtual functions 
	int getpRam();
	int getpStorage();
	int getpBattery();

	~Phone();
};

#endif