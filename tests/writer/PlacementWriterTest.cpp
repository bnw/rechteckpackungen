#include "cute.h"
#include "PlacementWriterTest.h"

#include "placement/Placement.h"
#include "instance/Instance.h"
#include "writer/PlacementWriter.h"
#include <string>
#include <sstream>


namespace rechteckpackungen {
void testPlacementWriter() {
	auto writer = new PlacementWriter();


	auto bounds = std::shared_ptr<PositionedRectangle>(new PositionedRectangle(0,0,0,0));
	auto instance = Instance(bounds);
	instance.addRectangle(Rectangle(2,3));
	instance.addRectangle(Rectangle(2,4));

	auto placement = std::shared_ptr<Placement>(new Placement());
	auto a = PositionedRectangle(Rectangle(2, 3), Coordinates(0, 1));
	auto b = PositionedRectangle(Rectangle(2, 4), Coordinates(3, 3));
	b.rotate();
	placement->add(a);
	placement->add(b);
	std::stringstream expected;
	expected << "0 2 1 4 0 0" << std::endl << "3 7 3 5 0 1";

	ASSERT_EQUAL(expected.str(), writer->toString(placement, instance));

	delete writer;
}

cute::suite make_suite_PlacementWriterTest() {
	cute::suite s { };
	s.push_back(CUTE(testPlacementWriter));
	return s;
}

}
