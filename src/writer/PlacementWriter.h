#ifndef SRC_WRITER_PLACEMENTWRITER_H_
#define SRC_WRITER_PLACEMENTWRITER_H_

#include "arrangement/Placement.h"
#include <string>
#include <sstream>

namespace rechteckpackungen {

class PlacementWriter {
public:
	std::string toString(Placement* placement);
};

}
#endif
