#include "cute.h"
#include "BStarTreeTest.h"

#include "BTree/BStarTree.h"
#include "arrangement/Placement.h"
#include "arrangement/PositionedRectangle.h"
#include "reader/PlacementReader.h"
#include <stdio.h>

namespace rechteckpackungen {

void testBStarTreeFromPlacementConstruction() {
	auto placement = new Placement();
	/*
	 * #####
	 * ####
	 * #  #
	 * #  ##
	 * #####
	 */
	auto root = new PositionedRectangle(0, 4, 0, 4);
	auto right = new PositionedRectangle(4, 6, 0, 2);
	auto top = new PositionedRectangle(0, 5, 4, 5);

	placement->add(root);
	placement->add(right);
	placement->add(top);

	auto tree = new BStarTree(placement);

	ASSERT(tree->getPositionedRectangle(tree->getRoot()) == root);
	ASSERT(tree->getPositionedRectangle(tree->getRoot()->getLeftChild()) == right);
	ASSERT(tree->getPositionedRectangle(tree->getRoot()->getRightChild()) == top);

	delete placement, tree;
}

void testBastTreemFromTextPlacementConstruction() {
	//Equal to "Figure 1" of B*-Tree paper
	std::stringstream fig1;
	fig1 << "0 6 0 6 0 0\n0 1 6 10 0 0\n1 3 6 8 0 0\n3 4 6 11 0 0\n4 5 6 9 0 0\n0 2 10 12 0 0\n2 5 11 12 0 0\n6 10 0 2 0 0\n6 8 2 4 0 0\n6 10 4 5 0 0\n6 9 5 11 0 0\n8 9 2 3 0 0";
	auto reader = PlacementReader();
	auto placement = reader.read(fig1);
	auto tree = new BStarTree(placement);

	auto n0 = tree->getRoot();
	auto n1 = n0->getRightChild();
	auto n2 = n1->getLeftChild();
	auto n3 = n2->getLeftChild();
	auto n4 = n3->getLeftChild();
	auto n5 = n1->getRightChild();
	auto n6 = n5->getLeftChild();
	auto n7 = n0->getLeftChild();
	auto n8 = n7->getRightChild();
	auto n9 = n8->getRightChild();
	auto n10 = n9->getRightChild();
	auto n11 = n8->getLeftChild();

	ASSERT(n0->getIndex() == 0);
	ASSERT(n1->getIndex() == 1);
	ASSERT(n2->getIndex() == 2);
	ASSERT(n3->getIndex() == 3);
	ASSERT(n4->getIndex() == 4);
	ASSERT(n5->getIndex() == 5);
	ASSERT(n6->getIndex() == 6);
	ASSERT(n7->getIndex() == 7);
	ASSERT(n8->getIndex() == 8);
	ASSERT(n9->getIndex() == 9);
	ASSERT(n10->getIndex() == 10);
	ASSERT(n11->getIndex() == 11);

	ASSERT(n7->hasLeftChild() == false);
	ASSERT(n11->hasChildren() == false);
	ASSERT(n9->hasLeftChild() == false);
	ASSERT(n5->hasRightChild() == false);

	delete placement, tree;
}

cute::suite make_suite_BStarTree() {
	cute::suite s;
	s.push_back(CUTE(testBStarTreeFromPlacementConstruction));
	s.push_back(CUTE(testBastTreemFromTextPlacementConstruction));
	return s;
}

}

