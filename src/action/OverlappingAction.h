#ifndef SRC_ACTION_OVERLAPPINGACTION_H_
#define SRC_ACTION_OVERLAPPINGACTION_H_

#include <string>
#include "reader/PlacementReader.h"
#include "algorithms/testForOverlapping/Sweepline.h"
#include <fstream>
#include <iostream>
#include "action/IFileAction.h"

namespace rechteckpackungen {

class OverlappingAction : public virtual IFileAction{
public:
	virtual ~OverlappingAction() {
	}
	void run(std::istream& input, std::ostream& output);
};

}

#endif
