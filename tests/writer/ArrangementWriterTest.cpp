#include "cute.h"
#include "ArrangementWriterTest.h"

#include "arrangement/Arrangement.h"
#include "writer/ArrangementWriter.h"
#include <string>
#include <sstream>


namespace rechteckpackungen {
void testArrangementWriter() {
	auto writer = new ArrangementWriter();

	auto arrangement = new Arrangement();
	arrangement->add(new PositionedRectangle(new Rectangle(2, 3), new Coordinates(0, 1)));
	arrangement->add(new PositionedRectangle(new Rectangle(2, 4), new Coordinates(3, 3)));
	std::stringstream expected;
	expected << "0 2 1 4" << std::endl << "3 5 3 7";

	ASSERTM(writer->toString(arrangement),writer->toString(arrangement) == expected.str());

	delete arrangement;
	delete writer;
}

cute::suite make_suite_ArrangementWriterTest() {
	cute::suite s { };
	s.push_back(CUTE(testArrangementWriter));
	return s;
}

}
