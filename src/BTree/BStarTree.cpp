#include "BStarTree.h"

//TODO Ugly as fuck

namespace rechteckpackungen {

void buildTreeRecursively(BTreeNode* rootNode, std::vector<std::vector<int>>& xBucket, std::vector<bool> visited, BStarTree* tree) {

	auto rootRectangle = tree->getPositionedRectangle(rootNode);
	auto rootIndex = rootNode->getIndex();

	//build left tree (rectangles to the right)
	visited.at(rootIndex) = true;
	int lowestUnvistedModuleInXBucket = -1;
	for (auto i : xBucket.at(rootRectangle->getXMax())) {
		if (visited.at(i) == true) {
			continue;
		}
		if (lowestUnvistedModuleInXBucket == -1) {
			lowestUnvistedModuleInXBucket = i;
		} else if (tree->getPositionedRectangle(lowestUnvistedModuleInXBucket)->getYMin() > tree->getPositionedRectangle(i)->getYMin()) {
			lowestUnvistedModuleInXBucket = i;
		}
	}
	if (lowestUnvistedModuleInXBucket != -1) {
		tree->setLeftChild(tree->at(rootIndex), tree->at(lowestUnvistedModuleInXBucket));
		buildTreeRecursively(tree->at(lowestUnvistedModuleInXBucket), xBucket, visited, tree);
	}

	//build right tree (rectangles above)
	for (auto i : xBucket.at(rootRectangle->getXMin())) {
		if (visited.at(i) == true) {
			continue;
		}
		if (rootRectangle->getYMax() == tree->getPositionedRectangle(i)->getYMin()) {
			tree->setRightChild(tree->at(rootIndex), tree->at(i));
			buildTreeRecursively(tree->at(i), xBucket, visited, tree);
			break;
		}
	}

}

BStarTree::BStarTree(Placement* placement) :
		BTree(placement->getPositionedRectangles()->size()) {
	positionedRectangles = new auto(*placement->getPositionedRectangles());
	auto xBucket = std::vector<std::vector<int>>(placement->getXMax() + 1);
	auto visited = std::vector<bool>(positionedRectangles->size(), false);
//	for(auto xBucketPosition : xBucket){
//		xBucketPosition = std::vector<Rectangle*>();
//	}

	/**
	 * Find root and fill xBucket
	 */
	for (int i = 0; i < positionedRectangles->size(); i++) {
		auto rectangle = positionedRectangles->at(i);
		if (rectangle->getXMin() == 0 && rectangle->getYMin() == 0) {
			setRoot(nodes.at(i));
		}
		xBucket.at(rectangle->getXMin()).push_back(i);
	}

	buildTreeRecursively(getRoot(), xBucket, visited, this);

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
