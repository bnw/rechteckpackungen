/*
 * An Placement represents a number of PositionedRecangles placed on a plane
 */

#ifndef SRC_ARRANGEMENT_PLACEMENT_H_
#define SRC_ARRANGEMENT_PLACEMENT_H_

#include <vector>
#include <algorithm>
#include "arrangement/PositionedRectangle.h"
#include "algorithms/sortInt/IIntSorter.h"

namespace rechteckpackungen {

class Placement {
public:
	Placement();
	~Placement();
	bool operator==(const Placement& other);
	void add(PositionedRectangle*);
	std::vector<PositionedRectangle*>* getPositionedRectangles();

	/*
	 * Sorts the positionedRectangles-vector according to the XMin-coordinate of the positioned rectangle
	 * Complexity: n * log(n)
	 */
	void sortPositionedRectanglesByXMin(sortInt::IIntSorter* sorter); //ToDo does not belong here?

	/*
	 * Complexity: n
	 */
	int getXMax();
private:
	std::vector<PositionedRectangle*>* positionedRectangles;

};

}

#endif
