#include "Placement.h"

namespace rechteckpackungen {

Placement::Placement() {
	positionedRectangles = new std::vector<PositionedRectangle*>;
}

Placement::~Placement() {
	for(auto positionedRectangle : *positionedRectangles){
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

bool comparePositionedRectanglesByXMin(const PositionedRectangle* a, const PositionedRectangle* b){ return a->getXMin() < b->getXMin(); }
void Placement::sortPositionedRectanglesByXMin() {
	sort(positionedRectangles->begin(), positionedRectangles->end(), comparePositionedRectanglesByXMin);
}

std::vector<PositionedRectangle*>* Placement::getPositionedRectangles() {
	return positionedRectangles;
}

void Placement::add(PositionedRectangle* positionedRectangle) {
	positionedRectangles->push_back(positionedRectangle);
}

}

