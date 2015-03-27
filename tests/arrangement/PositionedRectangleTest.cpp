#include "cute.h"
#include "PositionedRectangleTest.h"

#include "arrangement/PositionedRectangle.h"
#include "arrangement/Coordinates.h"

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

cute::suite make_suite_PositionedRectangleTest() {
	cute::suite s;
	s.push_back(CUTE(testContains));
	return s;
}

}

