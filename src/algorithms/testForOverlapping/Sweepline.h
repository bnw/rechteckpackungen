#ifndef SRC_ALGORITHMS_TESTFOROVERLAPPING_SWEEPLINE_H_
#define SRC_ALGORITHMS_TESTFOROVERLAPPING_SWEEPLINE_H_

#include "arrangement/Placement.h"
#include "arrangement/PositionedRectangle.h"
#include "algorithms/sortInt/BucketSort.h"
#include <list>

namespace rechteckpackungen {

class Sweepline {
public:
	/*
	 * Checks, if the inner of any two of the positioned rectangles in the placement overlap
	 * Complexity: n*k + n*log(n) where n = number of rectangles, k = max number of rectangles that intersect any vertical straight line
	 */
	bool hasOverlapping(Placement* placement);

private:
	bool doPositionedRectanglesOverlapVertically(PositionedRectangle a, PositionedRectangle b);
	std::vector<PositionedRectangle>* getPositionedRectanglesSortedByXMin(Placement* placement);
};

}

#endif
