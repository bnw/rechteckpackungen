#include "BStarTree.h"
#include <stdio.h>

namespace rechteckpackungen {

BStarTree::BStarTree(std::shared_ptr<std::vector<Rectangle>> rectangles) :
		BTree(rectangles->size()), rectangles(rectangles) {
}

BStarTree::~BStarTree() {
}

Rectangle* BStarTree::getRectangle(BTreeNode* node) {
	return &rectangles->at(node->getIndex());
}

Rectangle* BStarTree::getRectangle(int index) {
	return &rectangles->at(index);
}

}
