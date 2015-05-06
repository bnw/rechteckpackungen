#ifndef SRC_ACTION_FINDBESTBYENUMERATION_H_
#define SRC_ACTION_FINDBESTBYENUMERATION_H_

#include <istream>
#include <ostream>
#include <limits>
#include <iostream>
#include "reader/InstanceReader.h"
#include "action/IFileAction.h"
#include "algorithms/findBestPlacement/FindBestPlacementByEnumeration.h"

namespace rechteckpackungen {

class FindBestByEnumeration : public virtual IFileAction{
public:
	virtual ~FindBestByEnumeration() {
	}
	void run(std::istream& instance, std::ostream& output);
};

}

#endif /* SRC_ACTION_FINDBESTBYENUMERATION_H_ */
