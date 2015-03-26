#include "cute.h"
#include "SweeplineTest.h"

#include <memory>
#include "algorithms/testForOverlapping/Sweepline.h"

namespace rechteckpackungen {

void testSweeplineHasOverlapping() {
	Placement notOverlappingPlacement;
	notOverlappingPlacement.add(
			new PositionedRectangle(std::shared_ptr<Rectangle>(new Rectangle(2, 3)), std::shared_ptr<Coordinates>(new Coordinates(0, 1))));
	notOverlappingPlacement.add(
			new PositionedRectangle(std::shared_ptr<Rectangle>(new Rectangle(2, 4)), std::shared_ptr<Coordinates>(new Coordinates(3, 3))));

	//right adjacent
	Placement notOverlappingPlacement2;
	notOverlappingPlacement2.add(
			new PositionedRectangle(std::shared_ptr<Rectangle>(new Rectangle(3, 1)), std::shared_ptr<Coordinates>(new Coordinates(0, 0))));
	notOverlappingPlacement2.add(
			new PositionedRectangle(std::shared_ptr<Rectangle>(new Rectangle(1, 1)), std::shared_ptr<Coordinates>(new Coordinates(3, 0))));

	//top adjacent
	Placement notOverlappingPlacement3;
	notOverlappingPlacement3.add(new PositionedRectangle(0, 1, 0, 3));
	notOverlappingPlacement3.add(new PositionedRectangle(0, 1, 3, 4));

	Placement overlappingPlacement;
	overlappingPlacement.add(
			new PositionedRectangle(std::shared_ptr<Rectangle>(new Rectangle(3, 1)), std::shared_ptr<Coordinates>(new Coordinates(0, 0))));
	overlappingPlacement.add(
			new PositionedRectangle(std::shared_ptr<Rectangle>(new Rectangle(1, 1)), std::shared_ptr<Coordinates>(new Coordinates(2, 0))));

	Sweepline algorithm;
	ASSERT(algorithm.hasOverlapping(&notOverlappingPlacement) == false);
	ASSERT(algorithm.hasOverlapping(&notOverlappingPlacement2) == false);
	ASSERT(algorithm.hasOverlapping(&notOverlappingPlacement3) == false);
	ASSERT(algorithm.hasOverlapping(&overlappingPlacement) == true);
}

cute::suite make_suite_SweeplineTest() {
	cute::suite s;
	s.push_back(CUTE(testSweeplineHasOverlapping));
	return s;
}

}
