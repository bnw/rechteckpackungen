#include "cute.h"
#include "PositionedRectangleTest.h"

#include "placement/PositionedRectangle.h"
#include "placement/Coordinates.h"

namespace rechteckpackungen {

void testContains() {
	auto a = PositionedRectangle(0, 5, 0, 10);

	ASSERT_EQUAL(true, a.contains(a));
	ASSERT_EQUAL(true, a.contains(PositionedRectangle(2,4,2,4)));
	ASSERT_EQUAL(false, a.contains(PositionedRectangle(4,6,0,10)));

	ASSERT_EQUAL(true, a.contains(Coordinates(5, 10)));
	ASSERT_EQUAL(true, a.contains(Coordinates(5, 5)));
	ASSERT_EQUAL(true, a.contains(Coordinates(0, 0)));
	ASSERT_EQUAL(false, a.contains(Coordinates(10, 5)));
}

void testGetTopRightCoordinates(){
	auto a = PositionedRectangle(0, 5, 0, 10);
	auto aActual = a.getTopRightCoordinates();
	auto aExpected = Coordinates(5, 10);
	ASSERT(aExpected == aActual);

	auto b = PositionedRectangle(3, 8, 3, 13);
	auto bActual = b.getTopRightCoordinates();
	auto bExpected = Coordinates(8, 13);
	ASSERT(bExpected == bActual);
}

void testShift(){
	auto a = PositionedRectangle(0, 1, 2 , 3);
	a.shift(Coordinates(0,0));
	ASSERT(PositionedRectangle(0, 1, 2 , 3) == a);
	a.shift(Coordinates(10,20));
	ASSERT(PositionedRectangle(10, 11, 22 , 23) == a);
}

cute::suite make_suite_PositionedRectangleTest() {
	cute::suite s;
	s.push_back(CUTE(testContains));
	s.push_back(CUTE(testGetTopRightCoordinates));
	s.push_back(CUTE(testShift));
	return s;
}

}

