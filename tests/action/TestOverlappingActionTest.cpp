#include "cute.h"
#include "TestOverlappingActionTest.h"

#include "action/TestOverlappingAction.h"

namespace rechteckpackungen {

void testNoOverlapping() {
	auto action = TestOverlappingAction();
	std::stringstream input;
	input << "0 3 1 4 0 3"<< std::endl <<"3 5 3 7 0 0";
	std::stringstream output;
	action.run(input, output);
	std::stringstream expected;
	expected << "Has NO overlapping" <<std::endl;
	ASSERT_EQUAL(expected.str(), output.str());
}

void testWithOverlapping() {
	auto action = TestOverlappingAction();
	std::stringstream input;
	input << "0 4 1 4 0 3"<< std::endl <<"3 5 3 7 0 0";
	std::stringstream output;
	action.run(input, output);
	std::stringstream expected;
	expected << "Has overlapping" <<std::endl;
	ASSERT_EQUAL(expected.str(), output.str());
}

cute::suite make_suite_OverlappingActionTest() {
	cute::suite s;
	s.push_back(CUTE(testNoOverlapping));
	s.push_back(CUTE(testWithOverlapping));
	return s;
}

}
