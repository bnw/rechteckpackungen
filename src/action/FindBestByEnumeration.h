#ifndef SRC_ACTION_FINDBESTBYENUMERATION_H_
#define SRC_ACTION_FINDBESTBYENUMERATION_H_

#include <istream>
#include <ostream>
#include <limits>
#include <iostream>
#include "reader/InstanceReader.h"
#include "writer/PlacementWriter.h"
#include "algorithms/enumerateBStarTrees/Enumerator.h"
#include "algorithms/bStarTree2Placement/PlacementFactory.h"

namespace rechteckpackungen {

class FindBestByEnumeration {
public:
	void run(std::istream& instance, std::ostream& output);
};

}

#endif /* SRC_ACTION_FINDBESTBYENUMERATION_H_ */
