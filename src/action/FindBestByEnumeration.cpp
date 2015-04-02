#include "FindBestByEnumeration.h"

namespace rechteckpackungen {

void FindBestByEnumeration::run(std::istream& input, std::ostream& output) {
	auto reader = InstanceReader();
	auto instance = reader.read(input);
	auto enumerator = enumerateBStarTrees::Enumerator();
	auto placementFactory = bStarTree2Placement::PlacementFactory();
	std::shared_ptr<Placement> cheapestPlacement = nullptr;
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
		return true;
	});

	if (cheapestPlacement == nullptr) {
		output << "There is no way to fit the rectangles into the given bounds." << std::endl;
	} else {
		auto writer = PlacementWriter();
		output << writer.toString(cheapestPlacement) << std::endl;
	}

	delete instance;
}

}
