#ifndef PHONE_H
#define PHONE_H

#include <string>
#include <vector>
#include "product.h"

class Phone : public Product 
{
private:
	std::string cpu;
	int ram;
	float size;
	int storage;
	float rCamera;			//bc nowadays no phones have a single rear camera anymore (nokia 9 pureview)
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
	float getpSize();
	int getpRam();
	int getpStorage();
	int getpBattery();

	~Phone();
};

#endif