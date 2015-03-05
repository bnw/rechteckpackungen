#include "ArrangementWriter.h"

namespace rechteckpackungen {

std::string ArrangementWriter::toString(Arrangement* arrangement) {
	std::stringstream result;
	bool first = true;
	for (auto positionedRectangle : *(arrangement->getPositionedRectangles())) {
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
