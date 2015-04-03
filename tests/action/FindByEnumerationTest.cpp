#include "cute.h"
#include "FindByEnumerationTest.h"

#include "action/FindBestByEnumeration.h"
#include "instance/Instance.h"
#include "reader/InstanceReader.h"
#include <stdio.h>

namespace rechteckpackungen {

void testFindBest() {
	auto action = FindBestByEnumeration();
	auto instanceReader = InstanceReader();
	std::stringstream input;
	input << "0 5 1 7" << std::endl << "3 2" << std::endl << "2 4" << std::endl << "2 2";
	auto instance = instanceReader.read(input);

	auto result = action.findBest(instance);

	ASSERT_EQUAL(20, result->getArea());

	delete instance;
}

void integrationTest() {
	auto action = FindBestByEnumeration();
	std::stringstream input;
	input << "0 5 0 9" << std::endl << "3 1" << std::endl << "4 2" << std::endl << "3 2" << std::endl << "4 1" << std::endl << "3 3";
	std::stringstream output;
	action.run(input, output);

	std::stringstream expected;
	expected << "0 1 0 3 0 1" << std::endl << "1 5 0 2 0 0" << std::endl << "1 5 2 3 0 0" << std::endl << "0 2 3 6 0 1" << std::endl << "2 5 3 6 0 0" << std::endl;
	ASSERT_EQUAL(expected.str(), output.str());

}

cute::suite make_suite_FindByEnumerationTest() {
	cute::suite s;
	s.push_back(CUTE(testFindBest));
	s.push_back(CUTE(integrationTest));
	return s;
}

}
