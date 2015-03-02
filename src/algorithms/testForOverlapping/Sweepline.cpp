#include "Sweepline.h"

namespace rechteckpackungen {

/*
 * Approach:
 * - Sort placements by XMin
 * - Go through the ordered placements from left to right,
 *   maintaining a workingSet of placements that might overlap
 *   with the next placement
 */
bool Sweepline::hasOverlapping(Arrangement& arrangement) {
	auto placements = getPlacementsSortedByXMin(arrangement); // O(n * log(n))

	std::list<Placement*> workingSet;
	for (auto newPlacement : *placements) { // O(n)
		auto workingSetIterator = workingSet.begin();
		while (workingSetIterator != workingSet.end()) { // O(k)
			auto oldPlacement = *workingSetIterator;

			//remove old placements whose right border is left of the newPlacement
			if (oldPlacement->getXMax() < newPlacement->getXMin()) {
				workingSetIterator = workingSet.erase(workingSetIterator);
				continue;
			}

			//check for vertical overlapping
			if (doPlacementsOverlapVertically(oldPlacement, newPlacement)) {
				return true;
			}

			workingSetIterator++;
		}
		workingSet.push_back(newPlacement);
	}
	return false;
}

bool Sweepline::doPlacementsOverlapVertically(Placement* a, Placement* b) {
	if (a->getYMin() > b->getYMax() && a->getYMax() < b->getYMin()) {
		return false;
	}
	return true;
}

std::vector<Placement*>* Sweepline::getPlacementsSortedByXMin(
		Arrangement& arrangement) {
	arrangement.sortPlacementsByXMin();
	return arrangement.getPlacements();
}

}
