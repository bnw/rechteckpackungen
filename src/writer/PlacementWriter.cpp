#include "PlacementWriter.h"

namespace rechteckpackungen {

std::string PlacementWriter::toString(std::shared_ptr<Placement> placement) {
	std::stringstream result;
	bool first = true;
	for (auto positionedRectangle : *(placement->getPositionedRectangles())) {
		auto rotated = positionedRectangle->isRotated();
		auto rect = positionedRectangle->getRectangle();
		if (first) {
			first = false;
		} else {
			result << std::endl;
		}
		result << positionedRectangle->getXMin() << " ";
		result << positionedRectangle->getXMax() << " ";
		result << positionedRectangle->getYMin() << " ";
		result << positionedRectangle->getYMax() << " ";
		result << "0 "; //not mirrored
		result << (positionedRectangle->isRotated() ? "1" : "0");
	}
	return result.str();
}

}
