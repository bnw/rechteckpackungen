#include "cute.h"
#include "ArrangementReaderTest.h"

#include "../../src/reader/ArrangementReader.h"
#include "../../src/arrangement/Arrangement.h"
#include <stdio.h>
#include <stdexcept>

namespace rechteckpackungen {

void testArrangementReaderInvalidInput(){
	ArrangementReader reader;
	std::stringstream stream;
	stream << "1 2 3 4 5 6\n1 2 3 4 5\n1 2 3 4 5 6";
	ASSERT_THROWSM("Input needs exactly 6 numbers per row", {auto arrangement = reader.read(stream);}, std::runtime_error);
}

void testArrangementReader(){
	ArrangementReader reader;
	std::stringstream stream;
	stream << "0 2 1 4 0 3\n3 5 3 7 0 0";
	Arrangement expectedResult;
	expectedResult.add(new PositionedRectangle(new Rectangle(2, 3), new Coordinates(0, 1)));
	expectedResult.add(new PositionedRectangle(new Rectangle(2, 4), new Coordinates(3, 3)));
	auto arrangement = reader.read(stream);
	ASSERT(expectedResult == *arrangement);
}

cute::suite make_suite_ArrangementReader() {
	cute::suite s;
	s.push_back(CUTE(testArrangementReader));
	s.push_back(CUTE(testArrangementReaderInvalidInput));
	return s;
}

}
