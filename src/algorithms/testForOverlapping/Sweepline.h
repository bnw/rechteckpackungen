#ifndef SRC_ALGORITHMS_TESTFOROVERLAPPING_SWEEPLINE_H_
#define SRC_ALGORITHMS_TESTFOROVERLAPPING_SWEEPLINE_H_

#include "arrangement/Arrangement.h"
#include "arrangement/PositionedRectangle.h"
#include <list>

namespace rechteckpackungen {

class Sweepline {
public:
	/*
	 * Checks, if the inner of any two of the positioned rectangles in the arrangement overlap
	 * Complexity: n*k + n*log(n) where n = number of rectangles, k = max number of rectangles that intersect any vertical straight line
	 */
	bool hasOverlapping(Arrangement* arrangement);

private:
	bool doPositionedRectanglesOverlapVertically(PositionedRectangle* a, PositionedRectangle* b);
	std::vector<PositionedRectangle*>* getPositionedRectanglesSortedByXMin(Arrangement* arrangement);
};

}

#endif
