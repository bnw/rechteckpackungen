#include "TestOverlappingAction.h"

namespace rechteckpackungen {

void TestOverlappingAction::run(char const *filename) {
	auto arrangementReader = ArrangementReader();
	std::ifstream file;
	file.open(filename);
	if(!file.is_open()){
		std::cout << "Cannot read file " << filename << std::endl;
		return;
	}
	auto arrangement = arrangementReader.read(file);
	auto sweeplineAlgorithm = Sweepline();
	bool hasOverlapping = sweeplineAlgorithm.hasOverlapping(arrangement);

	if (hasOverlapping) {
		std::cout << "Has overlapping" << std::endl;
	} else {
		std::cout << "Has NO overlapping" << std::endl;
	}
}

}
