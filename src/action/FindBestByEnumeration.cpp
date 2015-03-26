#include "FindBestByEnumeration.h"

namespace rechteckpackungen {

void FindBestByEnumeration::run(std::istream& input, std::ostream& output) { //TODO make testable by providing output-stream
	auto reader = InstanceReader();
	auto instance = reader.read(input);
	auto enumerator = enumerateBStarTrees::Enumerator();
	auto placementFactory = bStarTree2Placement::PlacementFactory();
	std::shared_ptr<Placement> cheapestPlacement = nullptr;
	int costOfCheapestPlacement = std::numeric_limits<int>::max();
	enumerator.forEachBStarTree(instance->getRectangles(), [&](rechteckpackungen::BStarTree* tree)->void {
		auto placement = placementFactory.create(tree);
		if(costOfCheapestPlacement > placement->getArea()) {
			cheapestPlacement = placement;
			costOfCheapestPlacement = placement->getArea();
		}
	});

	auto writer = PlacementWriter();
	output << writer.toString(cheapestPlacement) << std::endl;

	delete instance;
}

}
