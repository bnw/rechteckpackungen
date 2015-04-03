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

void Placement::sortPositionedRectanglesByXMin(sortInt::IIntSorter* sortStrategy) {
	sortStrategy->sort((std::vector<void*>*) positionedRectangles, [](const void* a) {return ((PositionedRectangle*) a)->getXMin();});
}

void Placement::sortPositionedRectanglesByYMin(sortInt::IIntSorter* sortStrategy) {
	sortStrategy->sort((std::vector<void*>*) positionedRectangles, [](const void* a) {return ((PositionedRectangle*) a)->getYMin();});
}

int Placement::getXMax() const {
	auto rightmostRectangle = std::max_element(positionedRectangles->begin(), positionedRectangles->end(),
			[](const PositionedRectangle* a, const PositionedRectangle* b) {return a->getXMax() < b->getXMax();});
	return (*rightmostRectangle)->getXMax();
}

int Placement::getYMax() const {
	auto topmostRectangle = std::max_element(positionedRectangles->begin(), positionedRectangles->end(),
			[](const PositionedRectangle* a, const PositionedRectangle* b) {return a->getYMax() < b->getYMax();});
	return (*topmostRectangle)->getYMax();
}

int Placement::getArea() {
	return getYMax() * getXMax();
}

std::vector<PositionedRectangle*>* Placement::getPositionedRectangles() {
	return positionedRectangles;
}

std::unique_ptr<PositionedRectangle> Placement::getBounds() const {
	return std::unique_ptr<PositionedRectangle>(new PositionedRectangle(0, getXMax(), 0, getYMax()));
}

std::shared_ptr<std::vector<Rectangle>>Placement::getRectangles() {
	auto rectangles = std::shared_ptr<std::vector<Rectangle>>(new std::vector<Rectangle>);
	for(auto positionedRectangle : *positionedRectangles) {
		rectangles->push_back(positionedRectangle->getRectangle());
	}
	return rectangles;
}

void Placement::add(PositionedRectangle* positionedRectangle) {
	positionedRectangles->push_back(positionedRectangle);
}

}

