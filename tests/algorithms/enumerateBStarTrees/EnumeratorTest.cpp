#include "cute.h"
#include "EnumeratorTest.h"

#include "algorithms/enumerateBStarTrees/Enumerator.h"
#include "Rectangle.h"
#include "BTree/BStarTree.h"
#include <vector>

namespace rechteckpackungen {

void testEnumerator() {
	auto enumerator = enumerateBStarTrees::Enumerator();
	auto a = Rectangle(1, 1);
	auto b = Rectangle(2, 3);
	auto rectangles = std::shared_ptr<std::vector<Rectangle>>(new std::vector<Rectangle>());
	rectangles->push_back(a);
	rectangles->push_back(b);

	int count = 0;
	enumerator.forEachBStarTree(rectangles, [&](BStarTree* tree) {
		count++;
		return true;
	});
	ASSERT_EQUAL(8, count); // 8 = 2^2 * 2^1 = [number of trees] *  (2 ^ [number of not square blocks])

	count = 0;
	enumerator.forEachBStarTree(rectangles, [&](BStarTree* tree) {
		count++;
		if(count == 2) {
			return false;
		}
		return true;
	});
	ASSERT_EQUALM("Assert that iteration can be aborted", 2, count);
}

cute::suite make_suite_EnumeratorTest() {
	cute::suite s;
	s.push_back(CUTE(testEnumerator));
	return s;
}

}
