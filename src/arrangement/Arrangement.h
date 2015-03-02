/*
 * An Arrangement represents a number of Recangles placed in a plane
 */

#ifndef SRC_ARRANGEMENT_ARRANGEMENT_H_
#define SRC_ARRANGEMENT_ARRANGEMENT_H_

#include <vector>
#include <algorithm>
#include "Placement.h"

namespace rechteckpackungen {

class Arrangement {
public:
	Arrangement();
	~Arrangement();
	bool operator==(const Arrangement& other);
	void add(Placement*);
	std::vector<Placement*>* getPlacements();
	void sortPlacementsByXMin(); //ToDo does not belong here?
private:
	std::vector<Placement*>* placements;
};

}

#endif
