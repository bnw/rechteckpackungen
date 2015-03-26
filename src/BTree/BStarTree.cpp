#include "BStarTree.h"
#include <stdio.h>

namespace rechteckpackungen {

BStarTree::BStarTree(std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>> rectangles) :
		BTree(rectangles->size()), rectangles(rectangles) {
}

BStarTree::~BStarTree() {
//	delete rectangles;
}

std::shared_ptr<Rectangle> BStarTree::getRectangle(BTreeNode* node) {
	return rectangles->at(node->getIndex());
}

std::shared_ptr<Rectangle> BStarTree::getRectangle(int index) {
	return rectangles->at(index);
}

}
