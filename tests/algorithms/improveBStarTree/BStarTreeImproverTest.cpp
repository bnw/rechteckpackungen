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
 * aabbccdddde
 *
 * Allow 1 mutation.
 * Should result in something like:
 *
 * aadddd
 * aabbcce
 *
 * => area = 2 * 7
 */
void testThatMovementsAreFound() {
	std::stringstream placementText;
	placementText << "0 2 0 2 0 0" << endl << "2 4 0 1 0 0" << endl << "4 6 0 1 0 0" << endl << "6 10 0 1 0 0" << endl << "10 11 0 1 0 0";
	std::stringstream instanceText;
	instanceText << "0 100 0 100 " << endl << "2 2" << endl << "2 1" << endl << "2 1" << endl << "4 1" << endl << "1 1";

	auto instanceReader = InstanceReader();
	auto placementReader = PlacementReader();
	auto bStarTreeFactory = placement2BStarTree::BStarTreeFactory();
	auto bStarTreeImprover = improveBStarTree::BStarTreeImprover();
	auto placementFactory = bStarTree2Placement::PlacementFactory();

	auto instance = instanceReader.read(instanceText);
	auto initialPlacement = placementReader.read(placementText);

	auto initialBStarTree = bStarTreeFactory.create(initialPlacement);
	auto improvedBStarTree = bStarTreeImprover.improve(*initialBStarTree, *instance, 1);
	auto improvedPlacement = placementFactory.createBounded(*improvedBStarTree, *instance);

	ASSERT_EQUAL(2 * 7, improvedPlacement->getArea());
}

/*
 * aa      cc
 * aa      cc
 * aabbbdddcc
 *
 * Allow 2 mutations.
 * Should result in something like:
 *
 * aabdcc
 * aabdcc
 * aabdcc
 *
 * => area = 3 * 6
 */
void testThatRotationsAreFound() {
	std::stringstream placementText;
	placementText << "0 2 0 3 0 0" << endl << "2 5 0 1 0 0" << endl << "5 8 0 1 0 0" << endl << "8 10 0 3 0 0";
	std::stringstream instanceText;
	instanceText << "0 100 0 100 " << endl << "2 3" << endl << "1 3" << endl << "1 3" << endl << "2 3";

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

	ASSERT_EQUAL(3 * 6, improvedPlacement->getArea());
}

cute::suite make_suite_BStarTreeImproverTest() {
	cute::suite s;
	s.push_back(CUTE(testThatMovementsAreFound));
	s.push_back(CUTE(testThatRotationsAreFound));
	return s;
}

}
}
