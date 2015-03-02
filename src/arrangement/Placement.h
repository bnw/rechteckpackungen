/*
 * The placement of a Rectangle in the plane
 */

#ifndef SRC_ARRANGEMENT_PLACEMENT_H_
#define SRC_ARRANGEMENT_PLACEMENT_H_

#include "Coordinates.h"
#include "../Rectangle.h"

namespace rechteckpackungen {

class Placement {
public:
	Placement(Rectangle* rect, Coordinates* coord);
	bool operator==(const Placement& other);
private:
	Rectangle* rect;
	Coordinates* coord;
};

}

#endif /* SRC_ARRANGEMENT_PLACEMENT_H_ */
