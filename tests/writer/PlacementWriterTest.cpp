#include "cute.h"
#include "PlacementWriterTest.h"

#include "arrangement/Placement.h"
#include "writer/PlacementWriter.h"
#include <string>
#include <sstream>


namespace rechteckpackungen {
void testPlacementWriter() {
	auto writer = new PlacementWriter();

	auto placement = std::shared_ptr<Placement>(new Placement());
	placement->add(new PositionedRectangle(std::shared_ptr<Rectangle>(new Rectangle(2, 3)), std::shared_ptr<Coordinates>(new Coordinates(0, 1))));
	placement->add(new PositionedRectangle(std::shared_ptr<Rectangle>(new Rectangle(2, 4)), std::shared_ptr<Coordinates>(new Coordinates(3, 3))));
	std::stringstream expected;
	expected << "0 2 1 4" << std::endl << "3 5 3 7";

	ASSERTM(writer->toString(placement),writer->toString(placement) == expected.str());

	delete writer;
}

cute::suite make_suite_PlacementWriterTest() {
	cute::suite s { };
	s.push_back(CUTE(testPlacementWriter));
	return s;
}

}
