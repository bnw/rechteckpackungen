#include "Placement.h"

namespace rechteckpackungen {

Placement::Placement() {
	positionedRectangles = new std::vector<PositionedRectangle*>;
}

Placement::~Placement() {
	for (auto positionedRectangle : *positionedRectangles) {
		delete positionedRectangle;
	}
	delete positionedRectangles;
}

bool Placement::operator==(const Placement& other) {
	if (positionedRectangles->size() != other.positionedRectangles->size()) {
		return false;
	}
	for (int i = 0; i < positionedRectangles->size(); i++) {
		auto ownPositionedRectangle = (PositionedRectangle*) positionedRectangles->at(i);
		auto otherPositionedRectangle = (PositionedRectangle*) other.positionedRectangles->at(i);
		if (!(*ownPositionedRectangle == *otherPositionedRectangle)) {
			return false;
		}
	}
	return true;
}

void Placement::sortPositionedRectanglesByXMin(sortInt::IIntSorter* sorter) {
	sorter->sort((std::vector<void*>*) positionedRectangles, [](const void* a) {return ((PositionedRectangle*) a)->getXMin();});
}

void Placement::sortPositionedRectanglesByYMin(sortInt::IIntSorter* sorter) {
	sortPositionedRectanglesByYMin(sorter, positionedRectangles);
}

void Placement::sortPositionedRectanglesByYMin(sortInt::IIntSorter* sorter, std::vector<PositionedRectangle*>* positionedRectangles) {
	sorter->sort((std::vector<void*>*) positionedRectangles, [](const void* a) {return ((PositionedRectangle*) a)->getYMin();});
}

int Placement::getXMax() {
	auto rightmostRectangle = std::max_element(positionedRectangles->begin(), positionedRectangles->end(),
			[](const PositionedRectangle* a, const PositionedRectangle* b) {return a->getXMax() < b->getXMax();});
	return (*rightmostRectangle)->getXMax();
}

std::vector<PositionedRectangle*>* Placement::getPositionedRectangles() {
	return positionedRectangles;
}

std::vector<Rectangle*>* Placement::getRectangles() {
	auto rectangles = new std::vector<Rectangle*>;
	for(auto positionedRectangle : *positionedRectangles){
		rectangles->push_back(positionedRectangle->getRectangle());
	}
	return rectangles;
}

void Placement::add(PositionedRectangle* positionedRectangle) {
	positionedRectangles->push_back(positionedRectangle);
}

}

