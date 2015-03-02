#include "Sweepline.h"

namespace rechteckpackungen {

/*
 * Vorgehen:
 * Sortiere Rechtecke nach XMin
 * Gehe von links nach rechts durch die sortierung und nehme neue Rechtecke in mein working set auf und schmeiﬂe alte weg
 */
bool Sweepline::hasOverlapping(Arrangement& arrangement) {
	auto placements = getSortedPlacements(arrangement);

	std::list<Placement*> workingSet;
	for (auto newPlacement : *placements) {
		auto workingSetIterator = workingSet.begin();
		while (workingSetIterator != workingSet.end()) {
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

std::vector<Placement*>* Sweepline::getSortedPlacements(
		Arrangement& arrangement) {
	arrangement.sortPlacementsByXMin();
	return arrangement.getPlacements();
}

}
