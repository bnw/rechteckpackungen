#include "cute.h"
#include "RectangleTest.h"

void thisIsARectangleTest() {
	ASSERTM("start writing tests", false);	
}

cute::suite make_suite_Rectangle(){
	cute::suite s;
	s.push_back(CUTE(thisIsARectangleTest));
	return s;
}



