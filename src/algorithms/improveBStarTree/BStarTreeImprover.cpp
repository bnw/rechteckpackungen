#include "BStarTreeImprover.h"

namespace rechteckpackungen {

using bStarTree2Placement::PlacementFactory;

namespace improveBStarTree {

BStarTreeImprover::BStarTreeImprover() {
}

BStarTree* BStarTreeImprover::improve(const BStarTree& tree, const Instance& instance, unsigned k) const {
	auto placementFactory = PlacementFactory();
	auto subsetEnumerator = enumerateSubsets::Enumerator<BTreeNode*>();
	auto mutationEnumerator = enumerateBStarTreeMutations::Enumerator();
	BStarTree* currentOptimalTree = nullptr;
	int currentOptimalTreeArea = std::numeric_limits<int>::max();
	auto workingTree = BStarTree(tree);
	auto nodes = workingTree.getNodes();

	subsetEnumerator.forEachSubset(nodes, k, [&](const std::vector<BTreeNode*>& subset) {
		mutationEnumerator.forEachMutation(tree, subset, [&](const BStarTree& mutatedTree) {
			challengeOptimum(currentOptimalTree, currentOptimalTreeArea, mutatedTree, placementFactory, instance);
				});
	});

	return currentOptimalTree;
}

void BStarTreeImprover::challengeOptimum(BStarTree *&currentOptimalTree, int &currentOptimalTreeArea,
		const BStarTree &challenger,
		const PlacementFactory &placementFactory, const Instance &instance) const {
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
	}
}

}
}
