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

	enumerator.forEachBStarTree(rectangles, [&](BStarTree* tree){
		count++;
	});

	ASSERT_EQUAL(4, count);
}

cute::suite make_suite_EnumeratorTest() {
	cute::suite s;
	s.push_back(CUTE(testEnumerator));
	return s;
}

}
