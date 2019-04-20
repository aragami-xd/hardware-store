#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <vector>
#include "store.h"
#include "product.h"

using namespace std;

class Camera : public Store
{
public:
	Camera();

	vector<Product> loadingCamera;
	int totalCamera;
	Product *camera;

	virtual void sort(int toalProduct, Product *product);
	virtual void loadData();
	~Camera();

};

#endif