/*
 * An Placement represents a number of PositionedRecangles placed on a plane
 */

#ifndef SRC_ARRANGEMENT_PLACEMENT_H_
#define SRC_ARRANGEMENT_PLACEMENT_H_

#include <vector>
#include <algorithm>
#include <memory>
#include "arrangement/PositionedRectangle.h"
#include "Rectangle.h"
#include "algorithms/sortInt/IIntSorter.h"

namespace rechteckpackungen {

class Placement {
public:
	typedef std::shared_ptr<Placement> ptr;
	Placement();
	~Placement();
	bool operator==(const Placement& other);
	void add(PositionedRectangle);
	std::vector<PositionedRectangle>* getPositionedRectangles();
	std::shared_ptr<std::vector<Rectangle>> getRectangles();
	std::unique_ptr<PositionedRectangle> getBounds() const;

	/*
	 * Sorts the positionedRectangles-vector according to the XMin-coordinate of the positioned rectangle
	 */
	void sortPositionedRectanglesByXMin(sortInt::IIntSorter<PositionedRectangle>* sortStrategy);
	void sortPositionedRectanglesByYMin(sortInt::IIntSorter<PositionedRectangle>* sortStrategy);

	/*
	 * Complexity: n
	 */
	int getXMax() const;
	int getYMax() const;
	int getArea();
private:
	std::vector<PositionedRectangle>* positionedRectangles;

};

}

#endif
