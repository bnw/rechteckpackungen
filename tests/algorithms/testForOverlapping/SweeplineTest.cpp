#include "cute.h"
#include "SweeplineTest.h"

#include "algorithms/testForOverlapping/Sweepline.h"

namespace rechteckpackungen {

void testSweeplineHasOverlapping() {
	Placement notOverlappingPlacement;
	notOverlappingPlacement.add(
			new PositionedRectangle(new Rectangle(2, 3), new Coordinates(0, 1)));
	notOverlappingPlacement.add(
			new PositionedRectangle(new Rectangle(2, 4), new Coordinates(3, 3)));

	Placement overlappingPlacement;
	overlappingPlacement.add(
			new PositionedRectangle(new Rectangle(3, 3), new Coordinates(0, 1)));
	overlappingPlacement.add(
			new PositionedRectangle(new Rectangle(2, 4), new Coordinates(3, 3)));

	Placement overlappingPlacement2;
	overlappingPlacement2.add(
			new PositionedRectangle(new Rectangle(2, 4), new Coordinates(3, 3)));
	overlappingPlacement2.add(
			new PositionedRectangle(new Rectangle(2, 3), new Coordinates(1, 1)));

	Sweepline algorithm;
	ASSERT(algorithm.hasOverlapping(&notOverlappingPlacement) == false);
	ASSERT(algorithm.hasOverlapping(&overlappingPlacement) == true);
	ASSERT(algorithm.hasOverlapping(&overlappingPlacement2) == true);
}

cute::suite make_suite_SweeplineTest() {
	cute::suite s;
	s.push_back(CUTE(testSweeplineHasOverlapping));
	return s;
}

}
