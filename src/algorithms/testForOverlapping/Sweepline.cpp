#include "Sweepline.h"

namespace rechteckpackungen {

/*
 * Approach:
 * - Sort positioned rectangles by XMin
 * - Go through the ordered rectangles from left to right,
 *   maintaining a workingSet of rectangles that might overlap
 *   with the next rectangle
 */
bool Sweepline::hasOverlapping(Placement* placement) {
	auto positionedRectangles = getPositionedRectanglesSortedByXMin(placement); // O(n * log(n))

	std::list<PositionedRectangle*> workingSet;
	for (auto newPositionedRectangle : *positionedRectangles) { // O(n)
		auto workingSetIterator = workingSet.begin();
		while (workingSetIterator != workingSet.end()) { // O(k)
			auto oldPositionedRectangle = *workingSetIterator;

			//remove old positioned rectangles whose right border is left of the rectangle
			if (oldPositionedRectangle->getXMax() <= newPositionedRectangle->getXMin()) {
				workingSetIterator = workingSet.erase(workingSetIterator);
				continue;
			}

			//check for vertical overlapping
			if (doPositionedRectanglesOverlapVertically(oldPositionedRectangle, newPositionedRectangle)) {
				return true;
			}

			workingSetIterator++;
		}
		workingSet.push_back(newPositionedRectangle);
	}
	return false;
}

bool Sweepline::doPositionedRectanglesOverlapVertically(PositionedRectangle* a, PositionedRectangle* b) {
	if (a->getYMin() >= b->getYMax() || a->getYMax() <= b->getYMin()) {
		return false;
	}
	return true;
}

std::vector<PositionedRectangle*>* Sweepline::getPositionedRectanglesSortedByXMin(
		Placement* placement) {
	placement->sortPositionedRectanglesByXMin();
	return placement->getPositionedRectangles();
}

}
