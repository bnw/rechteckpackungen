#include "FindGoodPlacement.h"

namespace rechteckpackungen {

FindGoodPlacement::FindGoodPlacement(unsigned numberOfNodesThatCanBeMutated) :
		numberOfNodesThatCanBeMutated(numberOfNodesThatCanBeMutated) {
}

void FindGoodPlacement::run(std::istream &input, std::ostream &output) {
	auto instanceReader = InstanceReader();
	auto bStarTreeImprover = improveBStarTree::BStarTreeImprover();
	auto placementFactory = bStarTree2Placement::PlacementFactory();
	auto placementWriter = PlacementWriter();
	auto bStarTreeConstructor = constructGoodBStarTree::BStarTreeConstructor();

	Instance *instance = instanceReader.read(input);
	BStarTree *initialBStarTree = bStarTreeConstructor.create(*instance);

	auto errorMsg = "Did not find a solution that fits the given bounds.";

	if (initialBStarTree == nullptr) {
		output << errorMsg;
	} else {
		BStarTree* improvedBStarTree = bStarTreeImprover.improve(*initialBStarTree, *instance, numberOfNodesThatCanBeMutated);
		if (improvedBStarTree == nullptr) {
			output << errorMsg;
		} else {
			auto improvedPlacement = placementFactory.createBounded(*improvedBStarTree, *instance);
			output << placementWriter.toString(improvedPlacement);
			delete improvedBStarTree;
		}
		delete initialBStarTree;
	}
	delete instance;
}

}
