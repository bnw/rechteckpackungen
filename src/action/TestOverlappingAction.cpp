#include "TestOverlappingAction.h"

namespace rechteckpackungen {

void TestOverlappingAction::run(std::istream& input, std::ostream& output) {
	auto reader = PlacementReader();
	auto placement = reader.read(input);
	auto sweeplineAlgorithm = Sweepline();
	if (sweeplineAlgorithm.hasOverlapping(placement)) {
		output << "Has overlapping";
	} else {
		output << "Has NO overlapping";
	}
	output << std::endl;
	delete placement;
}

}
