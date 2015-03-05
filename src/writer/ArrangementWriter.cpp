#include "ArrangementWriter.h"

namespace rechteckpackungen {

std::string ArrangementWriter::toString(Arrangement* arrangement) {
	std::stringstream result;
	bool first = true;
	for (auto placement : *(arrangement->getPlacements())) {
		if (first) {
			first = false;
		} else {
			result << std::endl;
		}
		result << placement->getXMin() << " ";
		result << placement->getXMax() << " ";
		result << placement->getYMin() << " ";
		result << placement->getYMax();
	}
	return result.str();
}

}
