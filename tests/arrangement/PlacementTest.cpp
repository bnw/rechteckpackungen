#include "cute.h"
#include "PlacementTest.h"

#include "arrangement/Placement.h"
#include "algorithms/sortInt/BuiltIn.h"
#include <memory>

namespace rechteckpackungen {

void testPlacementSort() {
	auto expectedResult = new Placement;
	expectedResult->add(PositionedRectangle(Rectangle(0, 0), Coordinates(1, 0)));
	expectedResult->add(PositionedRectangle(Rectangle(0, 0), Coordinates(3, 0)));
	expectedResult->add(PositionedRectangle(Rectangle(0, 0), Coordinates(3, 0)));

	auto sorter = new sortInt::BuiltIn<PositionedRectangle>();
	auto subject = new Placement;
	subject->add(PositionedRectangle(Rectangle(0, 0), Coordinates(3, 0)));
	subject->add(PositionedRectangle(Rectangle(0, 0), Coordinates(1, 0)));
	subject->add(PositionedRectangle(Rectangle(0, 0), Coordinates(3, 0)));
	subject->sortPositionedRectanglesByXMin(sorter);

	ASSERT(*subject == *expectedResult);

	delete expectedResult;
	delete subject;
	delete sorter;
}

void testGetXMaxAndArea() {
	auto placement = new Placement;
	placement->add(PositionedRectangle(Rectangle(1, 2), Coordinates(4, 0)));
	placement->add(PositionedRectangle(Rectangle(1, 3), Coordinates(2, 0)));
	placement->add(PositionedRectangle(Rectangle(1, 16), Coordinates(3, 0)));

	ASSERT_EQUAL(5, placement->getXMax());
	ASSERT_EQUAL(5 * 16, placement->getArea());
	delete placement;
}

cute::suite make_suite_PlacementTest() {
	cute::suite s;
	s.push_back(CUTE(testPlacementSort));
	s.push_back(CUTE(testGetXMaxAndArea));
	return s;
}

}
