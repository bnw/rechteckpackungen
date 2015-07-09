#include "BStarTreeImprover.h"
#include <iostream>
namespace rechteckpackungen {

using bStarTree2Placement::PlacementFactory;

namespace improveBStarTree {

BStarTree *BStarTreeImprover::improve(const BStarTree &tree, const Instance &instance,
		unsigned numberOfNodesThatCanBeMutated) const {
	auto placementFactory = PlacementFactory();
	auto subsetEnumerator = enumerateSubsets::Enumerator<BTreeNode *>();
	auto mutationEnumerator = enumerateBStarTreeMutations::Enumerator(noRotation, noTreeMutation);
	BStarTree *currentOptimalTree = nullptr;
	int currentOptimalTreeArea = std::numeric_limits<int>::max();
	int previousOptimalTreeArea;
	while(true) {
		BStarTree workingTree = currentOptimalTree == nullptr ? tree : *currentOptimalTree;
		previousOptimalTreeArea = currentOptimalTreeArea;
		subsetEnumerator.forEachSubset(workingTree.getNodes(), numberOfNodesThatCanBeMutated, [&](const std::vector<BTreeNode *> &subset) {
			mutationEnumerator.forEachMutation(workingTree, subset, [&](const BStarTree &mutatedTree) {
				challengeOptimum(currentOptimalTree, currentOptimalTreeArea, mutatedTree, placementFactory, instance);
			});
		});
		if(previousOptimalTreeArea == currentOptimalTreeArea){
			break;
		}
	}
	return currentOptimalTree;
}

void BStarTreeImprover::challengeOptimum(BStarTree *&currentOptimalTree, int &currentOptimalTreeArea,
		const BStarTree &challenger,
		PlacementFactory &placementFactory, const Instance &instance) const {
	auto challengerPlacement = placementFactory.createBounded(challenger, instance);
	if (challengerPlacement == nullptr) { //placement does not fit into the bounds of the instance, abort!
		return;
	}
	auto challengerPlacementArea = challengerPlacement->getArea();
	if (challengerPlacementArea < currentOptimalTreeArea) {
		if (currentOptimalTree != nullptr) { //delete old optimum
			delete currentOptimalTree;
		}
		currentOptimalTree = new BStarTree(challenger); //copy tree, because we don't own challenger
		currentOptimalTreeArea = challengerPlacementArea;
		placementFactory.setMaxArea(currentOptimalTreeArea);
	}
}

}
}
