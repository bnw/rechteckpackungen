#include "Instance.h"

namespace rechteckpackungen {

Instance::Instance(Placement* area) {
	this->area = area;
	rectangles = new std::vector<Rectangle*>;
}

Instance::~Instance() {
	delete area;
	for(auto rectangle : *rectangles){
		delete rectangle;
	}
	delete rectangles;
}

void Instance::addRectangle(Rectangle* rect){
	rectangles->push_back(rect);
}

Placement* Instance::getArea(){
	return area;
}

}
