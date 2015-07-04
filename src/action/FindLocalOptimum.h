#ifndef SRC_ACTION_FINDLOCALOPTIMUM_H_
#define SRC_ACTION_FINDLOCALOPTIMUM_H_


#include <istream>
#include <ostream>
#include "reader/InstanceReader.h"
#include "reader/PlacementReader.h"
#include "writer/PlacementWriter.h"
#include "algorithms/placement2BStarTree/BStarTreeFactory.h"
#include "algorithms/improveBStarTree/BStarTreeImprover.h"
#include "algorithms/bStarTree2Placement/PlacementFactory.h"

namespace rechteckpackungen {

class FindLocalOptimum {
public:
	FindLocalOptimum(unsigned numberOfNodesThatCanBeMutated, bool noRotation, bool noTreeRotation);
	void run(std::istream& instanceInput, std::istream& initialPlacementInput, std::ostream& output);
protected:
	unsigned numberOfNodesThatCanBeMutated;
	bool noRotation;
	bool noTreeMutation;
};

}

#endif /* SRC_ACTION_FINDLOCALOPTIMUM_H_ */
