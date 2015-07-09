/*
 * An Placement represents a number of PositionedRecangles placed on a plane
 */

#ifndef SRC_PLACEMENT_PLACEMENT_H_
#define SRC_PLACEMENT_PLACEMENT_H_

#include <vector>
#include <algorithm>
#include <memory>
#include <limits>
#include "placement/PositionedRectangle.h"
#include "Rectangle.h"
#include "algorithms/sortInt/IIntSorter.h"

namespace rechteckpackungen {

class Placement {
public:
	typedef std::shared_ptr<Placement> ptr;

	/*
	 * If the constructor is called with an estimatedSize, the needed memory is allocated
	 * in one big chunk (rather than incrementally).
	 * This usually results in a noticeable performance improvement.
	 */
	Placement(int estimatedSize);

	Placement();

	~Placement();

	bool operator==(const Placement &other);

	void add(PositionedRectangle);

	std::vector<PositionedRectangle> *getPositionedRectangles();

	std::shared_ptr<std::vector<Rectangle>> getRectangles();

	void shift(const Coordinates offset);

	/*
	 * Sorts the positionedRectangles-vector according to the XMin-coordinate of the positioned rectangle
	 */
	void sortPositionedRectanglesByXMin(sortInt::IIntSorter<PositionedRectangle> *sortStrategy);

	void sortPositionedRectanglesByYMin(sortInt::IIntSorter<PositionedRectangle> *sortStrategy);

	/*
	 * Complexity of the following public functions: O(1)
	 */
	int getXMax() const;

	int getXMin() const;

	int getYMax() const;

	int getYMin() const;

	int getArea();

	PositionedRectangle getBoundingBox() const;

private:
	std::vector<PositionedRectangle> *positionedRectangles;
	int xMin = std::numeric_limits<int>::max();
	int xMax = std::numeric_limits<int>::min();
	int yMin = std::numeric_limits<int>::max();
	int yMax = std::numeric_limits<int>::min();

};

}

#endif
