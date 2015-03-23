#include "BStarTree.h"
#include <stdio.h>

namespace rechteckpackungen {

BStarTree::BStarTree(std::vector<Rectangle*>* rectangles) :
		BTree(rectangles->size()), rectangles(rectangles) {
}

BStarTree::~BStarTree() {
	delete rectangles;
}

Rectangle* BStarTree::getRectangle(BTreeNode* node) {
	return rectangles->at(node->getIndex());
}

Rectangle* BStarTree::getRectangle(int index) {
	return rectangles->at(index);
}

}
