#include "cute.h"
#include "InstanceReaderTest.h"

#include "reader/InstanceReader.h"
#include "arrangement/PositionedRectangle.h"
#include "instance/Instance.h"
#include <stdio.h>
#include <memory>

namespace rechteckpackungen {

void testInstanceReader() {
	auto reader = InstanceReader();
	std::stringstream input;
	input << "0 5 1 7" << std::endl << "3 2" << std::endl << "2 4" << std::endl << "B 1 3 5 8" << std::endl << std::endl << " " << std::endl;

	auto result = reader.read(input);
	auto expected = Instance(std::shared_ptr<PositionedRectangle>(new PositionedRectangle(0, 5, 1, 7)));
	expected.addRectangle(Rectangle(3, 2));
	expected.addRectangle(Rectangle(2, 4));

	ASSERT(*result == expected);
}

cute::suite make_suite_InstanceReaderTest() {
	cute::suite s;
	s.push_back(CUTE(testInstanceReader));
	return s;
}

}
