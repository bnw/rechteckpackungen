#include "cute.h"
#include "BStarTreeTest.h"

#include "BTree/BStarTree.h"
#include "arrangement/Placement.h"
#include "arrangement/PositionedRectangle.h"
#include "reader/PlacementReader.h"
#include "algorithms/placement2BStarTree/BStarTreeFactory.h"
#include <stdio.h>
#include <stdexcept>
#include <iostream>

namespace rechteckpackungen {

BStarTree* createTree(Placement* placement){
	auto factory = placement2BStarTree::BStarTreeFactory();
	return factory.create(placement);
}

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

	auto tree = createTree(placement);

	ASSERT(tree->getPositionedRectangle(tree->getRoot()) == root);
	ASSERT(tree->getRoot()->hasLeftChild());
	ASSERT(tree->getPositionedRectangle(tree->getRoot()->getLeftChild()) == right);
	ASSERT(tree->getRoot()->hasRightChild());
	ASSERT(tree->getPositionedRectangle(tree->getRoot()->getRightChild()) == top);

	delete placement, tree;
}

void testBStarTreeFromTextPlacementConstruction() {
	//Equal to "Figure 1" of B*-Tree paper
	std::stringstream fig1;
	fig1 << "0 6 0 6 0 0\n0 1 6 10 0 0\n1 3 6 8 0 0\n3 4 6 11 0 0\n4 5 6 9 0 0\n0 2 10 12 0 0\n2 5 11 12 0 0\n6 10 0 2 0 0\n6 8 2 4 0 0\n6 10 4 5 0 0\n6 9 5 11 0 0\n8 9 2 3 0 0";
	auto reader = PlacementReader();
	auto placement = reader.read(fig1);
	auto tree = createTree(placement);

	auto n0 = tree->getRoot();

	ASSERT(n0->hasRightChild());
	auto n1 = n0->getRightChild();

	ASSERT(n1->hasLeftChild());
	auto n2 = n1->getLeftChild();

	ASSERT(n2->hasLeftChild());
	auto n3 = n2->getLeftChild();

	ASSERT(n3->hasLeftChild());
	auto n4 = n3->getLeftChild();

	ASSERT(n1->hasRightChild());
	auto n5 = n1->getRightChild();

	ASSERT(n5->hasLeftChild());
	auto n6 = n5->getLeftChild();

	ASSERT(n0->hasLeftChild());
	auto n7 = n0->getLeftChild();

	ASSERT(n7->hasRightChild());
	auto n8 = n7->getRightChild();

	ASSERT(n8->hasRightChild());
	auto n9 = n8->getRightChild();

	ASSERT(n9->hasRightChild());
	auto n10 = n9->getRightChild();

	ASSERT(n8->hasLeftChild());
	auto n11 = n8->getLeftChild();

	ASSERT(*tree->getPositionedRectangle(n0) == PositionedRectangle(0,6,0,6));
	ASSERT(*tree->getPositionedRectangle(n1) == PositionedRectangle(0,1,6,10));
	ASSERT(*tree->getPositionedRectangle(n2) == PositionedRectangle(1, 3, 6, 8));
	ASSERT(*tree->getPositionedRectangle(n3) == PositionedRectangle(3, 4, 6, 11));
	ASSERT(*tree->getPositionedRectangle(n4) == PositionedRectangle(4, 5, 6, 9));
	ASSERT(*tree->getPositionedRectangle(n5) == PositionedRectangle(0, 2, 10, 12 ));
	ASSERT(*tree->getPositionedRectangle(n6) == PositionedRectangle(2, 5, 11, 12));
	ASSERT(*tree->getPositionedRectangle(n7) == PositionedRectangle(6, 10, 0, 2));
	ASSERT(*tree->getPositionedRectangle(n8) == PositionedRectangle(6, 8, 2, 4));
	ASSERT(*tree->getPositionedRectangle(n9) == PositionedRectangle(6, 10, 4, 5));
	ASSERT(*tree->getPositionedRectangle(n10) == PositionedRectangle(6, 9, 5, 11));
	ASSERT(*tree->getPositionedRectangle(n11) == PositionedRectangle(8, 9, 2, 3));

	ASSERT(n7->hasLeftChild() == false);
	ASSERT(n11->hasChildren() == false);
	ASSERT(n9->hasLeftChild() == false);
	ASSERT(n5->hasRightChild() == false);

	delete placement, tree;
}

void testThatBuiltTreesAreUnique() {
	auto placement = new Placement();
	/*
	 * 13
	 * 02
	 */
	auto b0 = new PositionedRectangle(0, 1, 0, 1);
	auto b1 = new PositionedRectangle(0, 1, 1, 2);
	auto b2 = new PositionedRectangle(1, 2, 0, 1);
	auto b3 = new PositionedRectangle(1, 2, 1, 2);

	placement->add(b0);
	placement->add(b1);
	placement->add(b2);
	placement->add(b3);
	auto tree = createTree(placement);

	/*
	 * According to specification, 3 must be left child of 1 and not right child of 2!
	 */
	auto n0 = tree->getRoot();
	auto n1 = n0->getRightChild();
	auto n2 = n0->getLeftChild();
	auto n3 = n1->getLeftChild();

	ASSERT(n0->getIndex() == 0);
	ASSERT(n1->getIndex() == 1);
	ASSERT(n2->getIndex() == 2);
	ASSERT(n3 != nullptr && n3->getIndex() == 3);

	ASSERT(n2->hasChildren() == false);

	delete placement, tree;
}

cute::suite make_suite_BStarTree() {
	cute::suite s;
	s.push_back(CUTE(testBStarTreeFromPlacementConstruction));
	s.push_back(CUTE(testBStarTreeFromTextPlacementConstruction));
//	s.push_back(CUTE(testThatBuiltTreesAreUnique)); TODO
	return s;
}

}

