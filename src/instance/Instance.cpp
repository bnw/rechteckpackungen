#include "Instance.h"

namespace rechteckpackungen {

Instance::Instance(std::shared_ptr<PositionedRectangle> bounds) :
		bounds(bounds) {
	rectangles = std::shared_ptr<std::vector<Rectangle>>(new std::vector<Rectangle>);
}

Instance::~Instance() {
}

bool Instance::operator==(const Instance& other) {
	if (rectangles->size() != other.rectangles->size()) {
		return false;
	}
	for (unsigned i = 0; i < rectangles->size(); i++) {
		auto ownRectangle = rectangles->at(i);
		auto otherRectangle = other.rectangles->at(i);
		if (!(ownRectangle == otherRectangle)) {
			return false;
		}
	}
	if (!(*bounds == *other.bounds)) {
		return false;
	}
	return true;
}

void Instance::addRectangle(Rectangle rect) {
	rectangles->push_back(rect);
}

std::shared_ptr<std::vector<Rectangle>>Instance::getRectangles() {
	return rectangles;
}

std::shared_ptr<PositionedRectangle> Instance::getBounds() {
	return bounds;
}

int Instance::getAreaSum() const{
	int areaSum = 0;
	for(auto rectangle : *rectangles){
		areaSum += rectangle.getArea();
	}
	return areaSum;
}

}
