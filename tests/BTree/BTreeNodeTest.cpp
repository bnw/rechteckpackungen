#include "cute.h"
#include "BTreeNodeTest.h"

#include "BTree/BTree.h"
#include "BTree/BTreeNode.h"
#include <iostream>

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

/**
 * Starting with:
 *               00
 *           /       \
 *       01              02
 *      /  \            /  \
 *   03      04      05      06
 *  /  \    /  \    /  \    /  \
 * 07  08  09  10  11  12  13  14
 *
 * Deleting 00
 * Expecting:
 *               02
 *           /       \
 *       01              06
 *      /  \            /  \
 *   03      04      05      13
 *  /  \    /  \    /  \     /
 * 07  08  09  10  11  12   14
 */
void testRemoveRootNode() {
	auto tree = BTree(15);
	tree.setRoot(tree.at(0));
	for (int i = 0; i <= 6; i++) {
		tree.setLeftChild(tree.at(i), tree.at(2 * i + 1));
		tree.setRightChild(tree.at(i), tree.at(2 * i + 2));
	}
	tree.remove(tree.at(0));

	ASSERT_EQUAL(tree.at(2), tree.getRoot());
	ASSERT_EQUAL(tree.at(3), tree.at(1)->getLeftChild());
	ASSERT_EQUAL(tree.at(4), tree.at(1)->getRightChild());
	ASSERT_EQUAL(tree.at(1), tree.at(2)->getLeftChild());
	ASSERT_EQUAL(tree.at(6), tree.at(2)->getRightChild());
	ASSERT_EQUAL(tree.at(7), tree.at(3)->getLeftChild());
	ASSERT_EQUAL(tree.at(8), tree.at(3)->getRightChild());
	ASSERT_EQUAL(tree.at(9), tree.at(4)->getLeftChild());
	ASSERT_EQUAL(tree.at(10), tree.at(4)->getRightChild());
	ASSERT_EQUAL(tree.at(11), tree.at(5)->getLeftChild());
	ASSERT_EQUAL(tree.at(12), tree.at(5)->getRightChild());
	ASSERT_EQUAL(tree.at(5), tree.at(6)->getLeftChild());
	ASSERT_EQUAL(tree.at(14), tree.at(6)->getRightChild());
	ASSERT_EQUAL(tree.at(13), tree.at(14)->getLeftChild());
}

/**
 * Starting with:
 *               00
 *           /       \
 *       01              02
 *      /  \            /  \
 *   03      04      05      06
 *  /  \    /  \    /  \    /  \
 * 07  08  09  10  11  12  13  14
 *
 * Deleting 02
 * Expecting:
 *               00
 *           /       \
 *       01              06
 *      /  \            /  \
 *   03      04      05      13
 *  /  \    /  \    /  \     /
 * 07  08  09  10  11  12   14
 */
void testRemoveNotRootNode() {
	auto tree = BTree(15);
	tree.setRoot(tree.at(0));
	for (int i = 0; i <= 6; i++) {
		tree.setLeftChild(tree.at(i), tree.at(2 * i + 1));
		tree.setRightChild(tree.at(i), tree.at(2 * i + 2));
	}
	tree.remove(tree.at(2));

	ASSERT_EQUAL(tree.at(0), tree.getRoot());
	ASSERT_EQUAL(tree.at(3), tree.at(1)->getLeftChild());
	ASSERT_EQUAL(tree.at(4), tree.at(1)->getRightChild());
	ASSERT_EQUAL(tree.at(1), tree.at(0)->getLeftChild());
	ASSERT_EQUAL(tree.at(6), tree.at(0)->getRightChild());
	ASSERT_EQUAL(tree.at(7), tree.at(3)->getLeftChild());
	ASSERT_EQUAL(tree.at(8), tree.at(3)->getRightChild());
	ASSERT_EQUAL(tree.at(9), tree.at(4)->getLeftChild());
	ASSERT_EQUAL(tree.at(10), tree.at(4)->getRightChild());
	ASSERT_EQUAL(tree.at(11), tree.at(5)->getLeftChild());
	ASSERT_EQUAL(tree.at(12), tree.at(5)->getRightChild());
	ASSERT_EQUAL(tree.at(5), tree.at(6)->getLeftChild());
	ASSERT_EQUAL(tree.at(14), tree.at(6)->getRightChild());
	ASSERT_EQUAL(tree.at(13), tree.at(14)->getLeftChild());
}

/**
 * Starting with:
 *               00
 *           /       \
 *       01              02
 *
 * Deleting 02
 * Expecting:
 *               00
 *           /       \
 *       01
 */
void testRemoveLeafNode() {
	auto tree = BTree(3);
	tree.setRoot(tree.at(0));
	for (int i = 0; i <= 0; i++) {
		tree.setLeftChild(tree.at(i), tree.at(2 * i + 1));
		tree.setRightChild(tree.at(i), tree.at(2 * i + 2));
	}
	tree.remove(tree.at(2));

	ASSERT_EQUAL(tree.at(0), tree.getRoot());
	ASSERT_EQUAL(tree.at(1), tree.at(0)->getLeftChild());
	ASSERT_EQUAL(false, tree.at(1)->hasRightChild());
}



/**
 * Starting with:
 *               00
 *           /       \
 *       01              02
 *      /  \            /  \
 *   03      04       05    06
 *
 * Deleting 06, 02
 * Expecting:
 *               00
 *           /       \
 *       01             05
 *      /  \
 *   03      04
 */
void testRemoveNodeWithOneChild() {
	auto tree = BTree(7);
	tree.setRoot(tree.at(0));
	for (int i = 0; i <= 2; i++) {
		tree.setLeftChild(tree.at(i), tree.at(2 * i + 1));
		tree.setRightChild(tree.at(i), tree.at(2 * i + 2));
	}
	tree.remove(tree.at(6));
	tree.remove(tree.at(2));

	ASSERT_EQUAL(tree.at(0), tree.getRoot());
	ASSERT_EQUAL(tree.at(3), tree.at(1)->getLeftChild());
	ASSERT_EQUAL(tree.at(4), tree.at(1)->getRightChild());
	ASSERT_EQUAL(tree.at(1), tree.at(0)->getLeftChild());
	ASSERT_EQUAL(tree.at(5), tree.at(0)->getRightChild());
	ASSERT_EQUAL(false, tree.at(5)->hasChildren());
}

cute::suite make_suite_BTreeNodeTest() {
	cute::suite s;
	s.push_back(CUTE(testGetClosestParentOfWhichIAmLeft));
	s.push_back(CUTE(testRemoveRootNode));
	s.push_back(CUTE(testRemoveNotRootNode));
	s.push_back(CUTE(testRemoveLeafNode));
	s.push_back(CUTE(testRemoveNodeWithOneChild));
	return s;
}

}
