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

void Placement::sortPositionedRectanglesByXMin(sortInt::ISortInt* sorter) {
	sorter->sort((std::vector<void*>*) positionedRectangles, [](const void* a) {return ((PositionedRectangle*) a)->getXMin();});
}

int Placement::getXMax() {
	auto rightmostRectangle = std::max_element(positionedRectangles->begin(), positionedRectangles->end(),
			[](const PositionedRectangle* a, const PositionedRectangle* b) {return a->getXMax() < b->getXMax();});
	return (*rightmostRectangle)->getXMax();
}

std::vector<PositionedRectangle*>* Placement::getPositionedRectangles() {
	return positionedRectangles;
}

void Placement::add(PositionedRectangle* positionedRectangle) {
	positionedRectangles->push_back(positionedRectangle);
}

}

