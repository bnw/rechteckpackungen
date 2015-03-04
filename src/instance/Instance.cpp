#include "Instance.h"

namespace rechteckpackungen {

Instance::Instance(Placement* area) {
	this->area = area;
	rectangles = new std::vector<Rectangle*>;
}

Instance::~Instance() {
	delete area;
	for (auto rectangle : *rectangles) {
		delete rectangle;
	}
	delete rectangles;
}

bool Instance::operator==(const Instance& other) {
	if (rectangles->size() != other.rectangles->size()) {
		return false;
	}
	for (int i = 0; i < rectangles->size(); i++) {
		auto ownRectangle = (Rectangle*) rectangles->at(i);
		auto otherRectangle = (Rectangle*) other.rectangles->at(i);
		if (!(*ownRectangle == *otherRectangle)) {
			return false;
		}
	}
	if (!(*area == *other.area)) {
		return false;
	}
	return true;
}

void Instance::addRectangle(Rectangle* rect) {
	rectangles->push_back(rect);
}

std::vector<Rectangle*>* Instance::getRectangles() {
	return rectangles;
}

Placement* Instance::getArea() {
	return area;
}

}
