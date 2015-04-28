#ifndef SRC_WRITER_PLACEMENTWRITER_H_
#define SRC_WRITER_PLACEMENTWRITER_H_

#include "placement/Placement.h"
#include <string>
#include <sstream>
#include <memory>

namespace rechteckpackungen {

class PlacementWriter {
public:
	std::string toString(std::shared_ptr<Placement> placement);
};

}
#endif
