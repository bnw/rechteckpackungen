#include "Arrangement.h"

namespace rechteckpackungen {

Arrangement::Arrangement() {
	positionedRectangles = new std::vector<PositionedRectangle*>;
}

Arrangement::~Arrangement() {
	for(auto positionedRectangle : *positionedRectangles){
		delete positionedRectangle;
	}
	delete positionedRectangles;
}

bool Arrangement::operator==(const Arrangement& other) {
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
void Arrangement::sortPositionedRectanglesByXMin() {
	sort(positionedRectangles->begin(), positionedRectangles->end(), comparePositionedRectanglesByXMin);
}

std::vector<PositionedRectangle*>* Arrangement::getPositionedRectangles() {
	return positionedRectangles;
}

void Arrangement::add(PositionedRectangle* positionedRectangle) {
	positionedRectangles->push_back(positionedRectangle);
}

}

