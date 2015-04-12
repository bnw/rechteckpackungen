#include "cute.h"
#include "EnumeratorTest.h"

#include "algorithms/enumerateBStarTreeMutations/Enumerator.h"
#include "BTree/BStarTree.h"
#include <memory>
#include <vector>

namespace rechteckpackungen {
namespace enumerateBStarTreeMutations {

void testMutationsEnumerator() {
	auto enumerator = Enumerator();
	auto a = Rectangle(1, 2);
	auto b = Rectangle(3, 3);
	auto rectangles = std::shared_ptr<std::vector<Rectangle>>(new std::vector<Rectangle>());
	rectangles->push_back(a); // node 0
	rectangles->push_back(b); // node 1
	auto tree = BStarTree(rectangles);
	tree.setRoot(tree.at(0));
	tree.setLeftChild(tree.at(0), tree.at(1));
	std::vector<BTreeNode*> subset;

	subset = {tree.at(0)};
	unsigned counter = 0;
	enumerator.forEachMutation(tree, subset, [&](const BStarTree& tree) {
		counter++;
	});
	ASSERT_EQUAL(8, counter); // 2 * 2 * 2 = [alternative positions (left child & right child of other node)] * [rotated and not rotated] * [swapped and not swapped]

	subset = {tree.at(0), tree.at(1)};
	counter = 0;
	enumerator.forEachMutation(tree, subset, [&](const BStarTree& tree) {
		counter++;
	});
	ASSERT_EQUAL(32, counter);

}

cute::suite make_suite_EnumeratorTest() {
	cute::suite s;
	s.push_back(CUTE(testMutationsEnumerator));
	return s;
}

}
}
