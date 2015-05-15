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

bool Placement::operator==(const Placement& other) {
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

void Placement::sortPositionedRectanglesByXMin(sortInt::IIntSorter<PositionedRectangle>* sortStrategy) {
	sortStrategy->sort(positionedRectangles, [](const PositionedRectangle a) {return a.getXMin();});
}

void Placement::sortPositionedRectanglesByYMin(sortInt::IIntSorter<PositionedRectangle>* sortStrategy) {
	sortStrategy->sort(positionedRectangles, [](const PositionedRectangle a) {return a.getYMin();});
}

int Placement::getXMax() const {
	auto rightmostRectangle = std::max_element(positionedRectangles->begin(), positionedRectangles->end(),
											   [](const PositionedRectangle a, const PositionedRectangle b) {
												   return a.getXMax() < b.getXMax();
											   });
	return (*rightmostRectangle).getXMax();
}

int Placement::getXMin() const {
	auto leftmostRectangle = std::min_element(positionedRectangles->begin(), positionedRectangles->end(),
											   [](const PositionedRectangle a, const PositionedRectangle b) {
												   return a.getXMin() < b.getXMin();
											   });
	return (*leftmostRectangle).getXMin();
}

int Placement::getYMax() const {
	auto topmostRectangle = std::max_element(positionedRectangles->begin(), positionedRectangles->end(),
											 [](const PositionedRectangle a, const PositionedRectangle b) {
												 return a.getYMax() < b.getYMax();
											 });
	return topmostRectangle->getYMax();
}

int Placement::getYMin() const {
	auto bottommostRectangle = std::min_element(positionedRectangles->begin(), positionedRectangles->end(),
											  [](const PositionedRectangle a, const PositionedRectangle b) {
												  return a.getYMin() < b.getYMin();
											  });
	return (*bottommostRectangle).getYMin();
}

int Placement::getArea() {
	if(positionedRectangles->empty()){
		return 0;
	}
	int xMax = 0;
	int yMax = 0;
	int xMin = std::numeric_limits<int>::max();
	int yMin = std::numeric_limits<int>::max();
	for (auto rectangle : *positionedRectangles) {
		xMax = std::max(xMax, rectangle.getXMax());
		yMax = std::max(yMax, rectangle.getYMax());
		xMin = std::min(xMin, rectangle.getXMin());
		yMin = std::min(yMin, rectangle.getYMin());
	}
	return (xMax - xMin) * (yMax - yMin);
}

std::vector<PositionedRectangle>* Placement::getPositionedRectangles() {
	return positionedRectangles;
}

std::unique_ptr<PositionedRectangle> Placement::getBounds() const {
	return std::unique_ptr<PositionedRectangle>(new PositionedRectangle(0, getXMax(), 0, getYMax()));
}

void Placement::shift(const Coordinates offset) {
	if(Coordinates(0,0) == offset){
		return;
	}
	for(auto i = positionedRectangles->begin(); i != positionedRectangles->end(); i++){
		i->shift(offset);
	}
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
}

}

