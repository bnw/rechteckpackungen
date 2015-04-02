#include "FindBestByEnumeration.h"

namespace rechteckpackungen {

/**
 * If a placement is found that optimal (i.e. area of placement = sum of area of rectangles) we stop.
 * This makes the algorithm really fast for instances that have an optimal solution.
 */
void FindBestByEnumeration::run(std::istream& input, std::ostream& output) {
	auto reader = InstanceReader();
	auto instance = reader.read(input);
	auto bestPlacement = findBest(instance);
	if (bestPlacement == nullptr) {
		output << "There is no way to fit the rectangles into the given bounds." << std::endl;
	} else {
		auto writer = PlacementWriter();
		output << writer.toString(bestPlacement) << std::endl;
	}

	delete instance;
}

Placement::ptr FindBestByEnumeration::findBest(Instance* instance) {
	auto enumerator = enumerateBStarTrees::Enumerator();
	auto placementFactory = bStarTree2Placement::PlacementFactory();
	Placement::ptr cheapestPlacement = nullptr;
	int areaOfCheapestPlacement = std::numeric_limits<int>::max();
	int theoreticalOptimalArea = instance->getAreaSum();
	enumerator.forEachBStarTree(instance->getRectangles(), [&](rechteckpackungen::BStarTree* tree)->bool {
		auto placement = placementFactory.createBounded(tree, *instance->getBounds()->getRectangle());
		if(placement != nullptr && areaOfCheapestPlacement > placement->getArea()) {
			cheapestPlacement = placement;
			areaOfCheapestPlacement = placement->getArea();
			if(theoreticalOptimalArea == areaOfCheapestPlacement) {
				return false; //break
			}
		}
		return true; //continue
	});
	return cheapestPlacement;
}

}
