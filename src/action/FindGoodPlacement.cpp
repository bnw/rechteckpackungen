#include "FindGoodPlacement.h"

namespace rechteckpackungen {

//TODO refactor
BStarTree* constructInitialBStarTree(Instance& instance) {
	auto placementFactory = bStarTree2Placement::PlacementFactory();
	auto rectangles = instance.getRectangles();
	auto tree = new BStarTree(instance.getRectangles());
	tree->setRoot(tree->at(0));
	for (unsigned i = 1; i < tree->getRectangles()->size(); i++) {
		auto partialRectangles = std::shared_ptr<std::vector<Rectangle>>(new std::vector<Rectangle>(rectangles->begin(), rectangles->begin() + i +1));
		auto partialTree = BStarTree(partialRectangles);
		for (auto newNode : partialTree.getNodes()) {
			auto originalNode = tree->at(newNode->getIndex());
			if (tree->isRoot(originalNode)) {
				partialTree.setRoot(newNode);
			}
			if (originalNode->hasLeftChild()) {
				partialTree.setLeftChild(newNode, partialTree.at(originalNode->getLeftChild()->getIndex()));
			}
			if (originalNode->hasRightChild()) {
				partialTree.setRightChild(newNode, partialTree.at(originalNode->getRightChild()->getIndex()));
			}
		}
		BTreeNode* newNode = partialTree.at(i);
		int bestParentId = 0;
		bool insertAsLeftChild = true;
		int cheapestPlacementArea = std::numeric_limits<int>::max();
		for (unsigned j = 0; j < i; j++) {
			auto possibleParent = partialTree.at(j);
			if (!possibleParent->hasLeftChild()) {
				partialTree.setLeftChild(possibleParent, newNode);
				auto placement = placementFactory.create(partialTree);
				if (cheapestPlacementArea > placement->getArea()) {
					bestParentId = j;
					insertAsLeftChild = true;
					cheapestPlacementArea = placement->getArea();
				}
				partialTree.removeChild(possibleParent, newNode);
			}
			if (!possibleParent->hasRightChild()) {
				partialTree.setRightChild(possibleParent, newNode);
				auto placement = placementFactory.create(partialTree);
				if (cheapestPlacementArea > placement->getArea()) {
					bestParentId = j;
					insertAsLeftChild = false;
					cheapestPlacementArea = placement->getArea();
				}
				partialTree.removeChild(possibleParent, newNode);
			}
		}
		if(insertAsLeftChild){
			tree->setLeftChild(tree->at(bestParentId), tree->at(i));
		}else{
			tree->setRightChild(tree->at(bestParentId), tree->at(i));
		}
	}
	return tree;
}

void FindGoodPlacement::run(std::istream& input, std::ostream& output) {
	auto instanceReader = InstanceReader();
	auto bStarTreeImprover = improveBStarTree::BStarTreeImprover();
	auto placementFactory = bStarTree2Placement::PlacementFactory();
	auto placementWriter = PlacementWriter();

	auto instance = instanceReader.read(input);
	auto initialBStarTree = constructInitialBStarTree(*instance);
	auto improvedBStarTree = bStarTreeImprover.improve(*initialBStarTree, *instance, 3);

	if (improvedBStarTree == nullptr) {
		output << "Did not find a solution that fits the given bounds.";
	} else {
		auto improvedPlacement = placementFactory.createBounded(*improvedBStarTree, *instance);
		output << placementWriter.toString(improvedPlacement);
	}

	delete instance;
	delete initialBStarTree;
	delete improvedBStarTree;
}

}
