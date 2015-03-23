#ifndef SRC_READER_PLACEMENTREADER_H_
#define SRC_READER_PLACEMENTREADER_H_

#include "util/explode.h"
#include "util/safeGetline.h"
#include "arrangement/Placement.h"
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdexcept>

namespace rechteckpackungen {

class PlacementReader {
public:
	Placement* read(std::istream& filename);
private:
	PositionedRectangle* getPositionedRectangleFromLine(std::string& line);
};

}

#endif
