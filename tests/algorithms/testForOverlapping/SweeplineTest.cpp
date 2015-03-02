#include "cute.h"
#include "SweeplineTest.h"

#include "algorithms/testForOverlapping/Sweepline.h"

namespace rechteckpackungen {

void testSweeplineHasOverlapping() {
	Arrangement notOverlappingArrangement;
	notOverlappingArrangement.add(
			new Placement(new Rectangle(2, 3), new Coordinates(0, 1)));
	notOverlappingArrangement.add(
			new Placement(new Rectangle(2, 4), new Coordinates(3, 3)));

	Arrangement overlappingArrangement;
	overlappingArrangement.add(
			new Placement(new Rectangle(3, 3), new Coordinates(0, 1)));
	overlappingArrangement.add(
			new Placement(new Rectangle(2, 4), new Coordinates(3, 3)));

	Arrangement overlappingArrangement2;
	overlappingArrangement2.add(
			new Placement(new Rectangle(2, 4), new Coordinates(3, 3)));
	overlappingArrangement2.add(
			new Placement(new Rectangle(2, 3), new Coordinates(1, 1)));

	Sweepline algorithm;
	ASSERT(algorithm.hasOverlapping(notOverlappingArrangement) == false);
	ASSERT(algorithm.hasOverlapping(overlappingArrangement) == true);
	ASSERT(algorithm.hasOverlapping(overlappingArrangement2) == true);
}

cute::suite make_suite_SweeplineTest() {
	cute::suite s;
	s.push_back(CUTE(testSweeplineHasOverlapping));
	return s;
}

}
