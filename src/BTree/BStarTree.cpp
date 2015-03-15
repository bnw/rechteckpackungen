#include "BStarTree.h"
#include <stdio.h>
//TODO Ugly

namespace rechteckpackungen {

void buildTreeRecursively(BTreeNode* rootNode, std::vector<std::vector<int>>& xBuckets, BStarTree* tree) {

	auto rootRectangle = tree->getPositionedRectangle(rootNode);
	auto rootIndex = rootNode->getIndex();

	//build left tree (rectangles to the right)
	auto currentXBucket = &xBuckets.at(rootRectangle->getXMax());
	if (!currentXBucket->empty()) {
		int lowestUnvistedModuleInXBucket = currentXBucket->back();
		currentXBucket->pop_back();
		tree->setLeftChild(tree->at(rootIndex), tree->at(lowestUnvistedModuleInXBucket));
		buildTreeRecursively(tree->at(lowestUnvistedModuleInXBucket), xBuckets, tree);
	}

	//build right tree (rectangles above)
	currentXBucket = &xBuckets.at(rootRectangle->getXMin());
	if (!currentXBucket->empty()) {
		auto lowestUnvistedModuleInXBucket = currentXBucket->back();
		if (rootRectangle->getYMax() == tree->getPositionedRectangle(lowestUnvistedModuleInXBucket)->getYMin()) {
			currentXBucket->pop_back();
			tree->setRightChild(tree->at(rootIndex), tree->at(lowestUnvistedModuleInXBucket));
			buildTreeRecursively(tree->at(lowestUnvistedModuleInXBucket), xBuckets, tree);
		}
	}

}

BStarTree::BStarTree(Placement* placement) :
		BTree(placement->getPositionedRectangles()->size()) {
	auto sorter = sortInt::BucketSort(true);
	positionedRectangles = new auto(*placement->getPositionedRectangles());
	placement->sortPositionedRectanglesByYMin(&sorter, positionedRectangles);
	auto xBuckets = std::vector<std::vector<int>>(placement->getXMax() + 1);

	/**
	 * Find root and fill xBuckets
	 */
	for (int i = 0; i < positionedRectangles->size(); i++) {
		auto rectangle = positionedRectangles->at(i);
		if (rectangle->getXMin() == 0 && rectangle->getYMin() == 0) {
			setRoot(nodes.at(i));
		} else {
			xBuckets.at(rectangle->getXMin()).push_back(i);
		}
	}

	buildTreeRecursively(getRoot(), xBuckets, this);
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
