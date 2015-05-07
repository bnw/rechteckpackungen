#include "cute.h"
#include "FindBestPlacementByEnumerationTest.h"

#include "algorithms/findBestPlacement/FindBestPlacementByEnumeration.h"
#include "instance/Instance.h"
#include "reader/InstanceReader.h"
#include <stdio.h>

namespace rechteckpackungen {
namespace findBestPlacement {

void testFindBest() {
	auto worker = FindBestPlacementByEnumeration();
	auto instanceReader = InstanceReader();
	std::stringstream input;
	input << "0 5 1 7" << std::endl << "3 2" << std::endl << "2 4" << std::endl << "2 2";
	auto instance = instanceReader.read(input);

	auto result = worker.findBest(instance);

	ASSERT(Coordinates(0,1) == result->getPositionedRectangles()->front().getBottomeLeftCoordinates());
	ASSERT_EQUAL(20, result->getArea());

	delete instance;
}

void testFindBestFails() {
	auto worker = FindBestPlacementByEnumeration();
	auto instanceReader = InstanceReader();
	std::stringstream input;
	input << "1 2 1 3" << std::endl << "1 1" << std::endl << "1 1" << std::endl << "1 1";
	auto instance = instanceReader.read(input);

	auto result = worker.findBest(instance);

	ASSERT_EQUAL(nullptr, result);

	delete instance;
}

cute::suite make_suite_FindBestPlacementByEnumerationTest() {
	cute::suite s;
	s.push_back(CUTE(testFindBest));
	s.push_back(CUTE(testFindBestFails));
	return s;
}

}
}
