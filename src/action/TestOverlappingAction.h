#ifndef SRC_ACTION_TESTOVERLAPPINGACTION_H_
#define SRC_ACTION_TESTOVERLAPPINGACTION_H_

#include <string>
#include "reader/PlacementReader.h"
#include "algorithms/testForOverlapping/Sweepline.h"
#include <fstream>
#include <iostream>

namespace rechteckpackungen {

class TestOverlappingAction {
public:
	void run(char const *filename);
};

}

#endif
