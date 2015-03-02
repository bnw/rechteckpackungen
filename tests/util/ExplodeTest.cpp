#include "cute.h"
#include "ExplodeTest.h"

namespace rechteckpackungen {

void testExplode() {
	std::string string = "test b xxx";
	std::vector<std::string> expected { "test", "b", "xxx" };
	auto result = explode(string, ' ');
	ASSERTM("Assert that split result is correct", expected == *result);
}

cute::suite make_suite_ExplodeTest() {
	cute::suite s;
	s.push_back(CUTE(testExplode));
	return s;
}

}
