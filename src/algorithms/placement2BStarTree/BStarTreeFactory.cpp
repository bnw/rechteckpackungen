#include "BStarTreeFactory.h"

namespace rechteckpackungen {
namespace placement2BStarTree {

BStarTree *BStarTreeFactory::create(Placement *placement) {
	auto reverseSorter = sortInt::BucketSort<PositionedRectangle>(true);
	placement->sortPositionedRectanglesByYMin(&reverseSorter);
	auto positionedRectangles = placement->getPositionedRectangles();
	auto tree = new BStarTree(placement->getRectangles());
	setRoot(*tree, *placement);
	auto xBuckets = buildXBuckets(*tree, *placement);

	buildTreeRecursively(tree->getRoot(), *xBuckets, tree, positionedRectangles);

	delete xBuckets;

	return tree;
}

std::vector<std::vector<int>> *BStarTreeFactory::buildXBuckets(BStarTree &tree, Placement &placementSortedByY) {
	auto xBuckets = new std::vector<std::vector<int>>((unsigned) placementSortedByY.getXMax() + 1);
	int rootIndex = tree.getRoot()->getIndex();
	auto sortedPositionedRectangles = placementSortedByY.getPositionedRectangles();
	for (unsigned i = 0; i < sortedPositionedRectangles->size(); i++) {
		if (i == (unsigned) rootIndex) {
			continue;
		}
		auto rectangle = sortedPositionedRectangles->at(i);
		xBuckets->at(rectangle.getXMin()).push_back(i);
	}
	return xBuckets;
}

void BStarTreeFactory::setRoot(BStarTree &tree, Placement &placement) {
	auto positionedRectangles = placement.getPositionedRectangles();
	auto expectedCoordinatesOfRoot = Coordinates(placement.getXMin(), placement.getYMin());
	for (unsigned i = 0; i < positionedRectangles->size(); i++) {
		if (positionedRectangles->at(i).getBottomeLeftCoordinates() == expectedCoordinatesOfRoot) {
			tree.setRoot(tree.at(i));
			return;
		}
	}
	throw std::runtime_error("Could not find root node. Is the provided placement compacted and non-empty?");
}

void BStarTreeFactory::buildTreeRecursively(BTreeNode *rootNode, std::vector<std::vector<int>> &xBuckets,
		BStarTree *tree, std::vector<PositionedRectangle> *positionedRectangles) {

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
