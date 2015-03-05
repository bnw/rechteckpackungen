#include "cute.h"
#include "InstanceReaderTest.h"

#include "reader/InstanceReader.h"
#include "arrangement/PositionedRectangle.h"
#include "instance/Instance.h"
#include <stdio.h>

namespace rechteckpackungen {

void testInstanceReader() {
	auto reader = InstanceReader();
	std::stringstream input;
	input << "0 5 1 7\n3 2\n2 4\nB 1 3 5 8";

	auto result = reader.read(input);
	auto expected = Instance(new PositionedRectangle(0, 5, 1, 7));
	expected.addRectangle(new Rectangle(3, 2));
	expected.addRectangle(new Rectangle(2, 4));

	ASSERT(*result == expected);
}

cute::suite make_suite_InstanceReaderTest() {
	cute::suite s;
	s.push_back(CUTE(testInstanceReader));
	return s;
}

}
