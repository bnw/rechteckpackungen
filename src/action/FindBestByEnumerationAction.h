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

class FindBestByEnumerationAction : public virtual IFileAction {
public:
	FindBestByEnumerationAction(bool noRotation = false) : noRotation(noRotation) { }

	virtual ~FindBestByEnumerationAction() {
	}

	void run(std::istream &instance, std::ostream &output);

protected:
	bool noRotation;
};

}

#endif /* SRC_ACTION_FINDBESTBYENUMERATION_H_ */
