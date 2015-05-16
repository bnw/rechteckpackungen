#include "BStarTreeFactory.h"

namespace rechteckpackungen {
namespace placement2BStarTree {

BStarTree* BStarTreeFactory::create(Placement* placement) {
	auto sorter = sortInt::BucketSort<PositionedRectangle>(true);
	placement->sortPositionedRectanglesByYMin(&sorter);
	auto positionedRectangles = placement->getPositionedRectangles();
	auto tree = new BStarTree(placement->getRectangles());
	auto xBuckets = std::vector<std::vector<int>>(placement->getXMax() + 1);

	int xMin = placement->getXMin();
	int yMin = placement->getYMin();
	/**
	 * Find root and fill xBuckets in O(n)
	 */
	for (unsigned i = 0; i < positionedRectangles->size(); i++) {
		auto rectangle = positionedRectangles->at(i);
		if (rectangle.getXMin() == xMin && rectangle.getYMin() == yMin) {
			tree->setRoot(tree->at(i));
		} else {
			xBuckets.at(rectangle.getXMin()).push_back(i);
		}
	}

	if(tree->getRoot() == nullptr){
		throw std::runtime_error("Could not find root node. Is the provided placement compacted and non-empty?");
	}

	buildTreeRecursively(tree->getRoot(), xBuckets, tree, positionedRectangles);

	return tree;
}

void BStarTreeFactory::buildTreeRecursively(BTreeNode* rootNode, std::vector<std::vector<int>>& xBuckets, BStarTree* tree,
		std::vector<PositionedRectangle>* positionedRectangles) {

	auto rootRectangle = positionedRectangles->at(rootNode->getIndex());
	auto rootIndex = rootNode->getIndex();

	//build left tree (rectangles to the right)
	auto currentXBucket = &xBuckets.at(rootRectangle.getXMax());
	if (!currentXBucket->empty()) {
		int lowestUnvisitedModuleInXBucket = currentXBucket->back();
		currentXBucket->pop_back();
		tree->setLeftChild(tree->at(rootIndex), tree->at(lowestUnvisitedModuleInXBucket));
		buildTreeRecursively(tree->at(lowestUnvisitedModuleInXBucket), xBuckets, tree, positionedRectangles);
	}

	//build right tree (rectangles above)
	currentXBucket = &xBuckets.at(rootRectangle.getXMin());
	if (!currentXBucket->empty()) {
		auto lowestUnvisitedModuleInXBucket = currentXBucket->back();
		auto closestParentOfWhichIAmLeft = rootNode->getClosestParentOfWhichIAmLeft();
		if (closestParentOfWhichIAmLeft == nullptr
				|| positionedRectangles->at(closestParentOfWhichIAmLeft->getIndex()).getYMax()
						> positionedRectangles->at(lowestUnvisitedModuleInXBucket).getYMin()) {
			currentXBucket->pop_back();
			tree->setRightChild(tree->at(rootIndex), tree->at(lowestUnvisitedModuleInXBucket));
			buildTreeRecursively(tree->at(lowestUnvisitedModuleInXBucket), xBuckets, tree, positionedRectangles);
		}
	}

}

}
}
