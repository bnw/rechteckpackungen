#include "BStarTreeFactory.h"

namespace rechteckpackungen {
namespace placement2BStarTree {

BStarTree* BStarTreeFactory::create(Placement* placement) {
	auto sorter = sortInt::BucketSort(true);
	auto positionedRectangles = new auto(*placement->getPositionedRectangles());
	placement->sortPositionedRectanglesByYMin(&sorter, positionedRectangles);
	auto tree = new BStarTree(positionedRectangles);
	auto xBuckets = std::vector<std::vector<int>>(placement->getXMax() + 1);

	/**
	 * Find root and fill xBuckets
	 */
	for (int i = 0; i < positionedRectangles->size(); i++) {
		auto rectangle = positionedRectangles->at(i);
		if (rectangle->getXMin() == 0 && rectangle->getYMin() == 0) {
			tree->setRoot(tree->at(i));
		} else {
			xBuckets.at(rectangle->getXMin()).push_back(i);
		}
	}

	buildTreeRecursively(tree->getRoot(), xBuckets, tree);

	return tree;
}

void BStarTreeFactory::buildTreeRecursively(BTreeNode* rootNode, std::vector<std::vector<int>>& xBuckets, BStarTree* tree) {

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

}
}
