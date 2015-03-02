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

cute::suite make_suite_Rectangle() {
	cute::suite s;
	s.push_back(CUTE(testRectangleConstructor));
	s.push_back(CUTE(testRectangleRotation));
	return s;
}


}
