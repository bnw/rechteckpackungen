#include "cute.h"
#include "BTreeNodeTest.h"

#include "BTree/BTree.h"
#include "BTree/BTreeNode.h"

namespace rechteckpackungen {
void testGetClosestParentOfWhichIAmLeft() {
	auto tree = BTree(7);
	tree.setRoot(tree.at(0));
	tree.setLeftChild(tree.at(0), tree.at(1));
	tree.setLeftChild(tree.at(1), tree.at(2));
	tree.setRightChild(tree.at(1), tree.at(3));
	tree.setRightChild(tree.at(3), tree.at(4));
	tree.setRightChild(tree.at(4), tree.at(5));
	tree.setRightChild(tree.at(0), tree.at(6));

	ASSERT(NULL == tree.at(6)->getClosestParentOfWhichIAmLeft());
	ASSERT_EQUAL(tree.at(0), tree.at(1)->getClosestParentOfWhichIAmLeft());
	ASSERT_EQUAL(tree.at(1), tree.at(2)->getClosestParentOfWhichIAmLeft());
	ASSERT_EQUAL(tree.at(0), tree.at(3)->getClosestParentOfWhichIAmLeft());
	ASSERT_EQUAL(tree.at(0), tree.at(4)->getClosestParentOfWhichIAmLeft());
	ASSERT_EQUAL(tree.at(0), tree.at(5)->getClosestParentOfWhichIAmLeft());
}

cute::suite make_suite_BTreeNodeTest() {
	cute::suite s;
	s.push_back(CUTE(testGetClosestParentOfWhichIAmLeft));
	return s;
}

}
