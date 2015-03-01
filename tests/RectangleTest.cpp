#include "cute.h"
#include "RectangleTest.h"
#include "../src/Rectangle.h"

namespace rechteckpackungen {

void testConstructor() {
	Rectangle r(1,2);
	ASSERT_EQUAL(1, r.getWidth());
	ASSERT_EQUAL(2, r.getHeight());
}

void testRotation(){
	Rectangle r(1,2);
	r.rotate();
	ASSERT_EQUAL(2, r.getWidth());
	ASSERT_EQUAL(1, r.getHeight());
}

cute::suite make_suite_Rectangle() {
	cute::suite s;
	s.push_back(CUTE(testConstructor));
	s.push_back(CUTE(testRotation));
	return s;
}


}
