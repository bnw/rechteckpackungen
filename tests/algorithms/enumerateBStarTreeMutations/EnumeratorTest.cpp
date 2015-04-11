#include "cute.h"
#include "EnumeratorTest.h"

#include "algorithms/enumerateBStarTreeMutations/Enumerator.h"
#include "BTree/BStarTree.h"
#include <memory>
#include <vector>

namespace rechteckpackungen {
namespace enumerateBStarTreeMutations {

void testEnumerator() {
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
	enumerator.forEachMutation(tree, subset, [&](const BStarTree& tree){
		counter++;
	});
	ASSERT_EQUAL(3, counter); //rotate a, swap a and b, dont rotate b (which is now the rectangle of node 0) because its square

	subset = {tree.at(0), tree.at(1)};
	counter = 0;
	enumerator.forEachMutation(tree, subset, [&](const BStarTree& tree){
		counter++;
	});
	ASSERT_EQUAL(9, counter); //rotate node 0 and dont rotate node 1, swap a and b, rotate node 0 and dont rotate node 1


}

cute::suite make_suite_EnumeratorTest() {
	cute::suite s;
	s.push_back(CUTE(testEnumerator));
	return s;
}

}
}
