/*
 * An Arrangement represents a number of Recangles placed in a plane
 */

#ifndef SRC_ARRANGEMENT_ARRANGEMENT_H_
#define SRC_ARRANGEMENT_ARRANGEMENT_H_

#include <vector>
#include "Placement.h"

namespace rechteckpackungen {

class Arrangement {
public:
	Arrangement();
	~Arrangement();
	bool operator==(const Arrangement& other);
	//bool hasOverlapping(); //TODO verschieben? Einzelne Klassen für Algorithmen?
	void add(Placement*);

private:
	std::vector<Placement*>* placements;
};

}

#endif
