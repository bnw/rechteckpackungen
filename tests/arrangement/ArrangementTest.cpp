#include "cute.h"
#include "ArrangementTest.h"

namespace rechteckpackungen {

void testArrangementSort(){
	Arrangement expectedResult;
	expectedResult.add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(1, 0)));
	expectedResult.add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(3, 0)));
	expectedResult.add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(3, 0)));

	Arrangement subject;
	subject.add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(3, 0)));
	subject.add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(1, 0)));
	subject.add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(3, 0)));
	subject.sortPositionedRectanglesByXMin();

	ASSERT(subject == expectedResult);
}

cute::suite make_suite_ArrangementTest() {
	cute::suite s;
	s.push_back(CUTE(testArrangementSort));
	return s;
}

}
