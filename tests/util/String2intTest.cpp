#include "cute.h"
#include "String2intTest.h"
#include "util/string2int.h"
#include <stdexcept>

namespace rechteckpackungen {

void testString2int() {
	ASSERT(string2int("0") == 0);
	ASSERT(string2int("55") == 55);
	ASSERT_THROWS(string2int("55a"), std::runtime_error);
}

cute::suite make_suite_String2intTest() {
	cute::suite s;
	s.push_back(CUTE(testString2int));
	return s;
}

}
