#include "cute.h"
#include "EnumeratorTest.h"

#include "algorithms/enumerateBStarTrees/Enumerator.h"
#include "Rectangle.h"
#include "BTree/BStarTree.h"
#include <vector>

namespace rechteckpackungen {

void testEnumerator() {
	auto enumerator = enumerateBStarTrees::Enumerator();
	auto a = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto b = std::shared_ptr<Rectangle>(new Rectangle(2, 2));
	auto rectangles = std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>>(new std::vector<std::shared_ptr<Rectangle>>());
	rectangles->push_back(a);
	rectangles->push_back(b);

	int count = 0;
	enumerator.forEachBStarTree(rectangles, [&](BStarTree* tree) {
		count++;
		return true;
	});
	ASSERT_EQUAL(4, count);

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
