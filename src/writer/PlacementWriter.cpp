#include "PlacementWriter.h"

namespace rechteckpackungen {

std::string PlacementWriter::toString(std::shared_ptr<Placement> placement, Instance& instance) {
	//Sort positioned rectangles according to rectangles in instance (TODO: refactor)
	auto positionedRectangles = *(placement->getPositionedRectangles());
	std::vector<PositionedRectangle> sortedRectangles;
	for (auto inputRectangle : *instance.getRectangles()) {
		for (auto positionedRectangleIterator = positionedRectangles.begin();
			 positionedRectangleIterator < positionedRectangles.end(); positionedRectangleIterator++) {
			auto resultRectangle = positionedRectangleIterator->getRectangle();
			if (resultRectangle.isRotated()) {
				resultRectangle.rotate();
			}
			if (resultRectangle == inputRectangle) {
				sortedRectangles.push_back(*positionedRectangleIterator);
				positionedRectangles.erase(positionedRectangleIterator);
			}
		}
	}

	//Create rectangle output
	std::stringstream result;
	bool first = true;
	for (auto positionedRectangle : sortedRectangles) {
		if (first) {
			first = false;
		} else {
			result << std::endl;
		}
		result << positionedRectangle.getXMin() << " ";
		result << positionedRectangle.getXMax() << " ";
		result << positionedRectangle.getYMin() << " ";
		result << positionedRectangle.getYMax() << " ";
		result << "0 "; //not mirrored
		result << (positionedRectangle.isRotated() ? "1" : "0");
	}
	return result.str();
}

}
