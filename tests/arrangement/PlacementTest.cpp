#include "cute.h"
#include "PlacementTest.h"

#include "arrangement/Placement.h"

namespace rechteckpackungen {

void testPlacementSort(){
	Placement expectedResult;
	expectedResult.add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(1, 0)));
	expectedResult.add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(3, 0)));
	expectedResult.add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(3, 0)));

	Placement subject;
	subject.add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(3, 0)));
	subject.add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(1, 0)));
	subject.add(new PositionedRectangle(new Rectangle(0, 0), new Coordinates(3, 0)));
	subject.sortPositionedRectanglesByXMin();

	ASSERT(subject == expectedResult);
}

cute::suite make_suite_PlacementTest() {
	cute::suite s;
	s.push_back(CUTE(testPlacementSort));
	return s;
}

}
