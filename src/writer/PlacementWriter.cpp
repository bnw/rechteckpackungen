#include "PlacementWriter.h"

namespace rechteckpackungen {

std::string PlacementWriter::toString(Placement* placement) {
	std::stringstream result;
	bool first = true;
	for (auto positionedRectangle : *(placement->getPositionedRectangles())) {
		if (first) {
			first = false;
		} else {
			result << std::endl;
		}
		result << positionedRectangle->getXMin() << " ";
		result << positionedRectangle->getXMax() << " ";
		result << positionedRectangle->getYMin() << " ";
		result << positionedRectangle->getYMax();
	}
	return result.str();
}

}
