#include "FindLocalOptimum.h"

namespace rechteckpackungen {

FindLocalOptimum::FindLocalOptimum(unsigned numberOfNodesThatCanBeMutated) :
		numberOfNodesThatCanBeMutated(numberOfNodesThatCanBeMutated) {
}

void FindLocalOptimum::run(std::istream &instanceInput, std::istream &initialPlacementInput, std::ostream &output) {
	auto instanceReader = InstanceReader();
	auto placementReader = PlacementReader();
	auto bStarTreeFactory = placement2BStarTree::BStarTreeFactory();
	auto bStarTreeImprover = improveBStarTree::BStarTreeImprover();
	auto placementFactory = bStarTree2Placement::PlacementFactory();
	auto placementWriter = PlacementWriter();

	Instance *instance = instanceReader.read(instanceInput);
	Placement *initialPlacement = placementReader.read(initialPlacementInput);

	BStarTree* initialBStarTree = bStarTreeFactory.create(initialPlacement);
	BStarTree* improvedBStarTree = bStarTreeImprover.improve(*initialBStarTree, *instance, numberOfNodesThatCanBeMutated);

	if (improvedBStarTree == nullptr) {
		output << "Neither the initial placement nor any mutations of it fit the bounds of the instance.";
	} else {
		auto improvedPlacement = placementFactory.createBounded(*improvedBStarTree, *instance);
		output << placementWriter.toString(improvedPlacement);
	}

	delete instance;
	delete initialPlacement;
	delete initialBStarTree;
	delete improvedBStarTree;
}

}
