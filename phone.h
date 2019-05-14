#ifndef PHONE_H
#define PHONE_H

#include <string>
#include <vector>
#include "product.h"

class Phone : public Product 
{
public: 
	Phone();
	Phone(string pCpu, int pRam, int pStorage, float pSize, vector<float> prCamera, float pfCamera, int pBattery);

	string cpu;
	int ram;
	float size;
	int storage;
	vector<float> rCamera;			//bc nowadays no phones have a single rear camera anymore (nokia 9 pureview)
	float fCamera;
	int battery;

	void setSpecs(string pCpu, int pRam, int pStorage, float pSize, vector<float> prCamera, float pfCamera, int pBattery);

	string getCpu();
	int getRam();
	float getSize();
	int getStorage();
	vector<float> getrCamera();
	float getfCamera();
	int getBattery();

	virtual void printSpecs();

	~Phone();
};

#endif