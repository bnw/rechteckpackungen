#ifndef SRC_ALGORITHMS_TESTFOROVERLAPPING_SWEEPLINE_H_
#define SRC_ALGORITHMS_TESTFOROVERLAPPING_SWEEPLINE_H_

#include "arrangement/Arrangement.h"
#include "arrangement/Placement.h"
#include <list>

namespace rechteckpackungen {

class Sweepline {
public:
	/*
	 * Checks, if the inner of any two of the placements in the arrangement overlap
	 * Complexity: n*k + n*log(n) where n = number of placements, k = max number of placements that intersect any vertical straight line
	 */
	bool hasOverlapping(Arrangement* arrangement);

private:
	bool doPlacementsOverlapVertically(Placement* a, Placement* b);
	std::vector<Placement*>* getPlacementsSortedByXMin(Arrangement* arrangement);
};

}

#endif
