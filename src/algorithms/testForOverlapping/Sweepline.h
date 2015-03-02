#ifndef SRC_ALGORITHMS_TESTFOROVERLAPPING_SWEEPLINE_H_
#define SRC_ALGORITHMS_TESTFOROVERLAPPING_SWEEPLINE_H_

#include "arrangement/Arrangement.h"
#include "arrangement/Placement.h"
#include <list>

namespace rechteckpackungen {

class Sweepline {
public:
	bool hasOverlapping(Arrangement& arrangement);

private:
	bool doPlacementsOverlapVertically(Placement* a, Placement* b);
	std::vector<Placement*>* getSortedPlacements(Arrangement& arrangement);
};

}

#endif
