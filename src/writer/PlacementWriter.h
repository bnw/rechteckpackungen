#ifndef SRC_WRITER_PLACEMENTWRITER_H_
#define SRC_WRITER_PLACEMENTWRITER_H_

#include "placement/Placement.h"
#include "instance/Instance.h"
#include <string>
#include <sstream>
#include <memory>

namespace rechteckpackungen {

class PlacementWriter {
public:
	/**
	 * Prints the placement in the same order as the rectangles appeared in instance.
	 */
	std::string toString(std::shared_ptr<Placement> placement, Instance& instance);
};

}
#endif
