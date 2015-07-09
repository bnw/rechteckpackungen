#include "BStarTreeConstructor.h"

namespace rechteckpackungen {
namespace constructGoodBStarTree {

BStarTree *BStarTreeConstructor::create(Instance &instance) {
	auto placementFactory = bStarTree2Placement::PlacementFactory();
	auto tree = new BStarTree(instance.getRectangles());
	auto nodes = tree->getNodes();
	tree->setRoot(tree->at(0));
	for (auto newNodeIterator = nodes.begin() + 1; newNodeIterator < nodes.end(); newNodeIterator++) {
		BTreeNode *newNode = *newNodeIterator;
		BTreeNode *bestParent = nullptr;
		bool insertAsLeftChild = true;
		bool foundAnyParent = false;
		bool foundSolutionWithinBounds = false;
		int cheapestPlacementArea = std::numeric_limits<int>::max();
		for (auto possibleParentIterator = nodes.begin();
			 possibleParentIterator != newNodeIterator; possibleParentIterator++) {
			BTreeNode *possibleParent = *possibleParentIterator;
			if (!possibleParent->hasLeftChild()) {
				tree->setLeftChild(possibleParent, newNode);
				auto placement = placementFactory.create(*tree);
				bool withinBounds = instance.getBounds()->contains(placement->getBoundingBox());
				if (placement != nullptr &&
					(
							(withinBounds && !foundSolutionWithinBounds) ||
							(withinBounds == foundSolutionWithinBounds &&
							 cheapestPlacementArea > placement->getArea())
					)) {
					bestParent = possibleParent;
					cheapestPlacementArea = placement->getArea();
					insertAsLeftChild = true;
					foundAnyParent = true;
					foundSolutionWithinBounds = withinBounds;
				}
				tree->removeChild(possibleParent, newNode);
			}
			if (!possibleParent->hasRightChild()) {
				tree->setRightChild(possibleParent, newNode);
				auto placement = placementFactory.create(*tree);
				bool withinBounds = instance.getBounds()->contains(placement->getBoundingBox());
				if (placement != nullptr &&
					(
							(withinBounds && !foundSolutionWithinBounds) ||
							(withinBounds == foundSolutionWithinBounds &&
							 cheapestPlacementArea > placement->getArea())
					)) {
					bestParent = possibleParent;
					cheapestPlacementArea = placement->getArea();
					insertAsLeftChild = false;
					foundAnyParent = true;
					foundSolutionWithinBounds = withinBounds;
				}
				tree->removeChild(possibleParent, newNode);
			}
		}
		if (!foundAnyParent) {
			return nullptr;
		}
		if (insertAsLeftChild) {
			tree->setLeftChild(bestParent, newNode);
		} else {
			tree->setRightChild(bestParent, newNode);
		}
	}
	return tree;
}

}
}