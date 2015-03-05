/*
 * An Arrangement represents a number of Recangles placed on a plane
 */

#ifndef SRC_ARRANGEMENT_ARRANGEMENT_H_
#define SRC_ARRANGEMENT_ARRANGEMENT_H_

#include <vector>
#include <algorithm>
#include "arrangement/PositionedRectangle.h"

namespace rechteckpackungen {

class Arrangement {
public:
	Arrangement();
	~Arrangement();
	bool operator==(const Arrangement& other);
	void add(PositionedRectangle*);
	std::vector<PositionedRectangle*>* getPositionedRectangles();

	/**
	 * Sorts the positionedRectangles-vector according to the XMin-coordinate of the positioned rectangle
	 * Complexity: n * log(n)
	 */
	void sortPositionedRectanglesByXMin(); //ToDo does not belong here?
private:
	std::vector<PositionedRectangle*>* positionedRectangles;
};

}

#endif
