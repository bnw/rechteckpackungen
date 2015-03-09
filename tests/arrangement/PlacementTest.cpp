#include "cute.h"
#include "PlacementTest.h"

#include "arrangement/Placement.h"
#include "algorithms/sortInt/BuiltIn.h"

namespace rechteckpackungen {

void testPlacementSort(){ //TODO Test all ISortInt implementations in a separate test
	auto expectedResult = new Placement;
	expectedResult->add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(1, 0)));
	expectedResult->add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(3, 0)));
	expectedResult->add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(3, 0)));

	auto sorter = new sortInt::BuiltIn();
	auto subject = new Placement;
	subject->add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(3, 0)));
	subject->add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(1, 0)));
	subject->add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(3, 0)));
	subject->sortPositionedRectanglesByXMin(sorter);

	ASSERT(*subject == *expectedResult);

	delete expectedResult, subject, sorter;
}

void testGetXMax(){
	auto placement = new Placement;
	placement->add(new PositionedRectangle(new Rectangle(1, 2), new Coordinates(4, 0)));
	placement->add(new PositionedRectangle(new Rectangle(1, 3), new Coordinates(2, 0)));
	placement->add(new PositionedRectangle(new Rectangle(1, 16), new Coordinates(3, 0)));

	ASSERT(placement->getXMax() == 5);
	delete placement;
}

cute::suite make_suite_PlacementTest() {
	cute::suite s;
	s.push_back(CUTE(testPlacementSort));
	s.push_back(CUTE(testGetXMax));
	return s;
}

}
