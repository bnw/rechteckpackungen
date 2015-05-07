#include "cute.h"
#include "PlacementTest.h"

#include "placement/Placement.h"
#include "placement/Coordinates.h"
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
	ASSERT_EQUAL((5 - 2) * (16 - 0), placement->getArea());
	delete placement;
}

void testPlacementShift() {
	auto placement = new Placement();
	placement->add(PositionedRectangle(Rectangle(1, 2), Coordinates(4, 0)));
	placement->add(PositionedRectangle(Rectangle(1, 3), Coordinates(2, 0)));
	placement->add(PositionedRectangle(Rectangle(1, 16), Coordinates(3, 0)));
	placement->shift(Coordinates(100,200));

	ASSERT_EQUAL(105, placement->getXMax());
	ASSERT_EQUAL((5 - 2) * (16 - 0), placement->getArea());
	ASSERT(PositionedRectangle(Rectangle(1, 2), Coordinates(104, 200)) == placement->getPositionedRectangles()->at(0));
	ASSERT(PositionedRectangle(Rectangle(1, 3), Coordinates(102, 200)) == placement->getPositionedRectangles()->at(1));
	ASSERT(PositionedRectangle(Rectangle(1, 16), Coordinates(103, 200)) == placement->getPositionedRectangles()->at(2));
	delete placement;
}

cute::suite make_suite_PlacementTest() {
	cute::suite s;
	s.push_back(CUTE(testPlacementSort));
	s.push_back(CUTE(testGetXMaxAndArea));
	s.push_back(CUTE(testPlacementShift));
	return s;
}

}
