#include "BStarTree.h"
#include <stdio.h>

namespace rechteckpackungen {

BStarTree::BStarTree(std::shared_ptr<std::vector<Rectangle>> rectangles) :
		BTree(rectangles->size()), rectangles(rectangles) {
}

BStarTree::BStarTree(const BStarTree& original) :
		BTree(original) {
	rectangles = std::shared_ptr<std::vector<Rectangle>>(new std::vector<Rectangle>(*original.rectangles)); //clone rectangles
}

BStarTree::~BStarTree() {
}

Rectangle* BStarTree::getRectangle(BTreeNode* node) const {
	return &rectangles->at(node->getIndex());
}

Rectangle* BStarTree::getRectangle(int index) const {
	return &rectangles->at(index);
}

std::shared_ptr<std::vector<Rectangle>> BStarTree::getRectangles() const{
	return rectangles;
}

}
