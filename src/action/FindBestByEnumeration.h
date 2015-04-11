#ifndef SRC_ACTION_FINDBESTBYENUMERATION_H_
#define SRC_ACTION_FINDBESTBYENUMERATION_H_

#include <istream>
#include <ostream>
#include <limits>
#include <iostream>
#include "instance/Instance.h"
#include "reader/InstanceReader.h"
#include "arrangement/Placement.h"
#include "writer/PlacementWriter.h"
#include "algorithms/enumerateBStarTrees/Enumerator.h"
#include "algorithms/bStarTree2Placement/PlacementFactory.h"
#include "action/IFileAction.h"

namespace rechteckpackungen {

class FindBestByEnumeration : public virtual IFileAction{
public:
	virtual ~FindBestByEnumeration() {
	}
	void run(std::istream& instance, std::ostream& output);
	// Public only for testability
	Placement::ptr findBest(Instance* instance);
};

}

#endif /* SRC_ACTION_FINDBESTBYENUMERATION_H_ */
