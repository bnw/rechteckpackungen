#include "FindGoodPlacement.h"

namespace rechteckpackungen {

void FindGoodPlacement::run(std::istream &input, std::ostream &output) {
	auto instanceReader = InstanceReader();
	auto bStarTreeImprover = improveBStarTree::BStarTreeImprover();
	auto placementFactory = bStarTree2Placement::PlacementFactory();
	auto placementWriter = PlacementWriter();
	auto bStarTreeConstructor = constructGoodBStarTree::BStarTreeConstructor();

	auto instance = instanceReader.read(input);
	auto initialBStarTree = bStarTreeConstructor.create(*instance);
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
