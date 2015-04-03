#include "cute.h"
#include "BStarTreeFactoryTest.h"

#include "BTree/BStarTree.h"
#include "arrangement/Placement.h"
#include "Rectangle.h"
#include "reader/PlacementReader.h"
#include "algorithms/placement2BStarTree/BStarTreeFactory.h"
#include <stdio.h>
#include <stdexcept>
#include <iostream>

namespace rechteckpackungen {

BStarTree* createTree(Placement* placement) {
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

	ASSERT(*tree->getRectangle(tree->getRoot()) == root->getRectangle());
	ASSERT(tree->getRoot()->hasLeftChild());
	ASSERT(*tree->getRectangle(tree->getRoot()->getLeftChild()) == right->getRectangle());
	ASSERT(tree->getRoot()->hasRightChild());
	ASSERT(*tree->getRectangle(tree->getRoot()->getRightChild()) == top->getRectangle());

	delete placement;
	delete tree;
}

void testBStarTreeFromTextPlacementConstruction() {
	//Equal to "Figure 1" of B*-Tree paper
	std::stringstream fig1;
	fig1
			<< "0 6 0 6 0 0\n0 1 6 10 0 0\n1 3 6 8 0 0\n3 4 6 11 0 0\n4 5 6 9 0 0\n0 2 10 12 0 0\n2 5 11 12 0 0\n6 10 0 2 0 0\n6 8 2 4 0 0\n6 10 4 5 0 0\n6 9 5 11 0 0\n8 9 2 3 0 0";
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

	ASSERT(*tree->getRectangle(n0) == Rectangle(6, 6));
	ASSERT(*tree->getRectangle(n1) == Rectangle(1, 4));
	ASSERT(*tree->getRectangle(n2) == Rectangle(2, 2));
	ASSERT(*tree->getRectangle(n3) == Rectangle(1, 5));
	ASSERT(*tree->getRectangle(n4) == Rectangle(1, 3));
	ASSERT(*tree->getRectangle(n5) == Rectangle(2, 2));
	ASSERT(*tree->getRectangle(n6) == Rectangle(3, 1));
	ASSERT(*tree->getRectangle(n7) == Rectangle(4, 2));
	ASSERT(*tree->getRectangle(n8) == Rectangle(2, 2));
	ASSERT(*tree->getRectangle(n9) == Rectangle(4, 1));
	ASSERT(*tree->getRectangle(n10) == Rectangle(3, 6));
	ASSERT(*tree->getRectangle(n11) == Rectangle(1, 1));

	ASSERT(n7->hasLeftChild() == false);
	ASSERT(n11->hasChildren() == false);
	ASSERT(n9->hasLeftChild() == false);
	ASSERT(n5->hasRightChild() == false);

	delete placement;
	delete tree;
}

/**
 * d
 * dccc
 * d b
 * dab
 */
void testThatThereCanBeSpaceBetweenTwoRectangles() {
	auto placement = new Placement();
	auto a = new PositionedRectangle(1, 2, 0, 1);
	auto b = new PositionedRectangle(2, 3, 0, 2);
	auto c = new PositionedRectangle(1, 4, 2, 3);
	auto d = new PositionedRectangle(0, 1, 0, 4);

	placement->add(a);
	placement->add(b);
	placement->add(c);
	placement->add(d);
	auto tree = createTree(placement);

	auto root = tree->getRoot();
	ASSERT(d->getRectangle() == *tree->getRectangle(root));
	ASSERT(root->hasLeftChild());
	ASSERT(root->hasRightChild() == false);
	ASSERT(a->getRectangle() == *tree->getRectangle(root->getLeftChild()));
	ASSERT(root->getLeftChild()->hasLeftChild());
	ASSERT(b->getRectangle() == *tree->getRectangle(root->getLeftChild()->getLeftChild()));
	ASSERT(root->getLeftChild()->hasRightChild());
	ASSERT(c->getRectangle() == *tree->getRectangle(root->getLeftChild()->getRightChild()));
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
	ASSERT(n0->hasRightChild());
	auto n1 = n0->getRightChild();
	ASSERT(n0->hasLeftChild());
	auto n2 = n0->getLeftChild();
	ASSERT(n1->hasLeftChild());
	auto n3 = n1->getLeftChild();

	ASSERT(b0->getRectangle() == *tree->getRectangle(n0));
	ASSERT(b1->getRectangle() == *tree->getRectangle(n1));
	ASSERT(b2->getRectangle() == *tree->getRectangle(n2));
	ASSERT(b3->getRectangle() == *tree->getRectangle(n3));

	ASSERT_EQUAL(false, n2->hasChildren());

	delete placement;
	delete tree;
}

cute::suite make_suite_BStarTreeFactory() {
	cute::suite s;
	s.push_back(CUTE(testBStarTreeFromPlacementConstruction));
	s.push_back(CUTE(testBStarTreeFromTextPlacementConstruction));
	s.push_back(CUTE(testThatThereCanBeSpaceBetweenTwoRectangles));
	s.push_back(CUTE(testThatBuiltTreesAreUnique));
	return s;
}

}

