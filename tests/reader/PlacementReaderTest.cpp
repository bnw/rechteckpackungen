#include "cute.h"
#include "PlacementReaderTest.h"

#include "../../src/reader/PlacementReader.h"
#include "../../src/arrangement/Placement.h"
#include <stdio.h>
#include <stdexcept>
#include <memory>

namespace rechteckpackungen {

void testPlacementReaderInvalidInput(){
	PlacementReader reader;
	std::stringstream stream;
	stream << "1 2 3 4 5 6\n1 2 3 4 5\n1 2 3 4 5 6";
	ASSERT_THROWSM("Input needs exactly 6 numbers per row", {auto placement = reader.read(stream);}, std::runtime_error);
}

void testPlacementReader(){
	PlacementReader reader;
	std::stringstream stream;
	stream << "0 2 1 4 0 3\n3 5 3 7 0 0";
	Placement expectedResult;
	expectedResult.add(new PositionedRectangle(Rectangle(2, 3), Coordinates(0, 1)));
	expectedResult.add(new PositionedRectangle(Rectangle(2, 4), Coordinates(3, 3)));
	auto placement = reader.read(stream);
	ASSERT(expectedResult == *placement);
	delete placement;
}

cute::suite make_suite_PlacementReader() {
	cute::suite s;
	s.push_back(CUTE(testPlacementReader));
	s.push_back(CUTE(testPlacementReaderInvalidInput));
	return s;
}

}
