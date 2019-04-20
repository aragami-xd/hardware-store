#include "camera.h"
#include "product.h"
#include <string>

using namespace std;

//implement the default camera constructor
Camera::Camera()
{
}

//implement the camera sort function
void Camera::sort(int totalProduct, Product *product)
{
	for (int i=0; i<totalProduct; i++) {
		if (product[i].getProductType() == "camera") {
			loadingCamera.push_back(product[i]);
		}
	}
}


//implement the virtual camera loadData function
void Camera::loadData()
{
	totalCamera = loadingCamera.size();
	camera = new Camera[totalCamera];
	for (int i=0; i<totalCamera; i++) {
		camera[i] = loadingCamera[i];
	}
	loadingCamera.clear();
}

//implement the camera destructor
Camera::~Camera()
{
}

