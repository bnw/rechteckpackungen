#include "cute.h"
#include "EnumeratorTest.h"

#include "algorithms/enumerateSubsets/Enumerator.h"
#include <vector>
#include <math.h>

namespace rechteckpackungen {
namespace enumerateSubsets {

void testEnumerator() {
	auto enumerator = Enumerator();
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	std::vector<void*> set = { &a, &b, &c, &d, &e };
	std::vector<std::vector<void*>> collectedSubsets;
	enumerator.forEachSubset(set, 3, [&](const std::vector<void*>* subset) {
		collectedSubsets.push_back(std::vector<void*>(*subset));
	});
	ASSERT_EQUAL(10, collectedSubsets.size()); // 10 = 5nCr3
}

cute::suite make_suite_EnumeratorTest() {
	cute::suite s;
	s.push_back(CUTE(testEnumerator));
	return s;
}

}
}
