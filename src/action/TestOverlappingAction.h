#ifndef SRC_ACTION_TESTOVERLAPPINGACTION_H_
#define SRC_ACTION_TESTOVERLAPPINGACTION_H_

#include <string>
#include "reader/PlacementReader.h"
#include "algorithms/testForOverlapping/Sweepline.h"
#include <fstream>
#include <iostream>
#include "action/IFileAction.h"

namespace rechteckpackungen {

class TestOverlappingAction : public virtual IFileAction{
public:
	virtual ~TestOverlappingAction() {
	}
	void run(std::istream& input, std::ostream& output);
};

}

#endif
