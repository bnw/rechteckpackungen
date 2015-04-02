#include "cute.h"
#include "RectangleTest.h"
#include "../src/Rectangle.h"

namespace rechteckpackungen {

void testRectangleConstructor() {
	Rectangle r(1,2);
	ASSERT_EQUAL(1, r.getWidth());
	ASSERT_EQUAL(2, r.getHeight());
}

void testRectangleRotation(){
	Rectangle r(1,2);
	r.rotate();
	ASSERT_EQUAL(2, r.getWidth());
	ASSERT_EQUAL(1, r.getHeight());
}

void testRectangleContains(){
	Rectangle r1(5,2);
	Rectangle r2(1,3);
	Rectangle r3(4,2);
	ASSERT(r1.contains(r1));
	ASSERT(!r1.contains(r2));
	ASSERT(r1.contains(r3));
}

cute::suite make_suite_Rectangle() {
	cute::suite s;
	s.push_back(CUTE(testRectangleConstructor));
	s.push_back(CUTE(testRectangleRotation));
	s.push_back(CUTE(testRectangleContains));
	return s;
}


}
