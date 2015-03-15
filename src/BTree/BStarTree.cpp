#include "BStarTree.h"
#include <stdio.h>

namespace rechteckpackungen {

BStarTree::BStarTree(std::vector<PositionedRectangle*>* positionedRectangles) :
		BTree(positionedRectangles->size()), positionedRectangles(positionedRectangles) {
}

BStarTree::~BStarTree() {
	delete positionedRectangles;
}

PositionedRectangle* BStarTree::getPositionedRectangle(BTreeNode* node) {
	return positionedRectangles->at(node->getIndex());
}

PositionedRectangle* BStarTree::getPositionedRectangle(int index) {
	return positionedRectangles->at(index);
}

}
