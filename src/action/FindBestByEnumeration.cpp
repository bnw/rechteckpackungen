#include "FindBestByEnumeration.h"

namespace rechteckpackungen {

void FindBestByEnumeration::run(std::istream& input, std::ostream& output) {
	auto reader = InstanceReader();
	auto instance = reader.read(input);
    auto worker = findBestPlacement::FindBestPlacementByEnumeration();
	auto writer = PlacementWriter();
	Placement::ptr bestPlacement = worker.findBest(instance);

	if (bestPlacement == nullptr) {
		output << "There is no way to fit the rectangles into the given bounds." << std::endl;
	} else {
		output << writer.toString(bestPlacement) << std::endl;
	}

	delete instance;
}

}
