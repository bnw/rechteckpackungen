#include "Placement.h"

namespace rechteckpackungen {

Placement::Placement(int estimatedSize) {
	positionedRectangles = new std::vector<PositionedRectangle>;
	positionedRectangles->reserve(estimatedSize);
}

Placement::Placement() :
		Placement(1) {
}

Placement::~Placement() {
	delete positionedRectangles;
}

bool Placement::operator==(const Placement &other) {
	if (positionedRectangles->size() != other.positionedRectangles->size()) {
		return false;
	}
	for (unsigned i = 0; i < positionedRectangles->size(); i++) {
		auto ownPositionedRectangle = positionedRectangles->at(i);
		auto otherPositionedRectangle = other.positionedRectangles->at(i);
		if (!(ownPositionedRectangle == otherPositionedRectangle)) {
			return false;
		}
	}
	return true;
}

void Placement::sortPositionedRectanglesByXMin(sortInt::IIntSorter<PositionedRectangle> *sortStrategy) {
	sortStrategy->sort(positionedRectangles, [](const PositionedRectangle a) { return a.getXMin(); });
}

void Placement::sortPositionedRectanglesByYMin(sortInt::IIntSorter<PositionedRectangle> *sortStrategy) {
	sortStrategy->sort(positionedRectangles, [](const PositionedRectangle a) { return a.getYMin(); });
}

int Placement::getXMax() const {
	return xMax;
}

int Placement::getXMin() const {
	return xMin;
}

int Placement::getYMax() const {
	return yMax;
}

int Placement::getYMin() const {
	return yMin;
}

int Placement::getArea() {
	if(positionedRectangles->size() == 0){
		return 0;
	}
	return (xMax - xMin) * (yMax - yMin);
}

std::vector<PositionedRectangle> *Placement::getPositionedRectangles() {
	return positionedRectangles;
}

void Placement::shift(const Coordinates offset) {
	if (Coordinates(0, 0) == offset) {
		return;
	}
	for (auto i = positionedRectangles->begin(); i != positionedRectangles->end(); i++) {
		i->shift(offset);
	}
	xMin += offset.getX();
	xMax += offset.getX();
	yMin += offset.getY();
	yMax += offset.getY();
}

std::shared_ptr<std::vector<Rectangle>> Placement::getRectangles() {
	auto rectangles = std::shared_ptr<std::vector<Rectangle>>(new std::vector<Rectangle>);
	for (auto positionedRectangle : *positionedRectangles) {
		rectangles->push_back(positionedRectangle.getRectangle());
	}
	return rectangles;
}

void Placement::add(PositionedRectangle positionedRectangle) {
	positionedRectangles->push_back(positionedRectangle);
	xMin = std::min(positionedRectangle.getXMin(), xMin);
	xMax = std::max(positionedRectangle.getXMax(), xMax);
	yMin = std::min(positionedRectangle.getYMin(), yMin);
	yMax = std::max(positionedRectangle.getYMax(), yMax);
}

PositionedRectangle Placement::getBoundingBox() const {
	return PositionedRectangle(xMin, xMax, yMin, yMax);
}

}

