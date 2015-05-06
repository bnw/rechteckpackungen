#ifndef SRC_ACTION_FINDGOODPLACEMENT_H_
#define SRC_ACTION_FINDGOODPLACEMENT_H_

#include "action/IFileAction.h"
#include "algorithms/placement2BStarTree/BStarTreeFactory.h"
#include "algorithms/improveBStarTree/BStarTreeImprover.h"
#include "algorithms/bStarTree2Placement/PlacementFactory.h"
#include "algorithms/constructGoodBStarTree/BStarTreeConstructor.h"
#include "reader/InstanceReader.h"
#include "writer/PlacementWriter.h"
#include <istream>
#include <ostream>
#include <iostream>
#include <limits>
#include <vector>
#include <memory>

namespace rechteckpackungen {

class FindGoodPlacement: public virtual IFileAction {
public:
	virtual ~FindGoodPlacement() {
	}
	void run(std::istream& input, std::ostream& output);
};

}

#endif /* SRC_ACTION_FINDGOODPLACEMENT_H_ */
