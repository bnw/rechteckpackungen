#include "cute.h"
#include "BStarTreeImproverTest.h"

#include <sstream>
#include "reader/InstanceReader.h"
#include "reader/PlacementReader.h"
#include "algorithms/placement2BStarTree/BStarTreeFactory.h"
#include "algorithms/improveBStarTree/BStarTreeImprover.h"
#include "algorithms/bStarTree2Placement/PlacementFactory.h"

using std::endl;

namespace rechteckpackungen {
namespace improveBStarTree {

/*
 * aa
 * aabbccdd
 *
 * Allow 2 mutations. Since there are only right children, switching rectangles does not change area.
 * Should result in something like:
 *
 * aabc
 * aabcdd
 *
 * => area = 2*6
 */
void testThatRotationsAreFound() {
	std::stringstream placementText;
	placementText << "0 2 0 2 0 0" << endl << "2 4 0 1 0 0" << endl << "4 6 0 1 0 0" << endl << "6 8 0 1 0 0";
	std::stringstream instanceText;
	instanceText << "0 100 0 100 " << endl << "3 3" << endl << "2 1" << endl << "2 1" << endl << "2 1";

	auto instanceReader = InstanceReader();
	auto placementReader = PlacementReader();
	auto bStarTreeFactory = placement2BStarTree::BStarTreeFactory();
	auto bStarTreeImprover = improveBStarTree::BStarTreeImprover();
	auto placementFactory = bStarTree2Placement::PlacementFactory();

	auto instance = instanceReader.read(instanceText);
	auto initialPlacement = placementReader.read(placementText);

	auto initialBStarTree = bStarTreeFactory.create(initialPlacement);
	auto improvedBStarTree = bStarTreeImprover.improve(*initialBStarTree, *instance, 2);
	auto improvedPlacement = placementFactory.createBounded(*improvedBStarTree, *instance);

	ASSERT_LESS_EQUAL(improvedPlacement->getArea(), 2 * 6);
}

cute::suite make_suite_BStarTreeImproverTest() {
	cute::suite s;
	s.push_back(CUTE(testThatRotationsAreFound));
	return s;
}

}
}
