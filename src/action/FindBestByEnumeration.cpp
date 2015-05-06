#include "FindBestByEnumeration.h"

namespace rechteckpackungen {

void FindBestByEnumeration::run(std::istream& input, std::ostream& output) {
	auto reader = InstanceReader();
	auto instance = reader.read(input);
    auto worker = findBestPlacement::FindBestPlacementByEnumeration();
	auto bestPlacement = worker.findBest(instance);
	if (bestPlacement == nullptr) {
		output << "There is no way to fit the rectangles into the given bounds." << std::endl;
	} else {
		auto writer = PlacementWriter();
		output << writer.toString(bestPlacement) << std::endl;
	}

	delete instance;
}

}
