/*
 * The placement of a single Rectangle in the plane
 */

#ifndef SRC_ARRANGEMENT_POSITIONEDRECTANGLE_H_
#define SRC_ARRANGEMENT_POSITIONEDRECTANGLE_H_

#include "Coordinates.h"
#include "../Rectangle.h"

namespace rechteckpackungen {

class PositionedRectangle {
public:
	PositionedRectangle(Rectangle* rect, Coordinates* coord);
	PositionedRectangle(int xMin, int xMax, int yMin, int yMax);
	~PositionedRectangle();
	bool operator==(const PositionedRectangle& other);
	int getXMin() const;
	int getXMax() const;
	int getYMin() const;
	int getYMax() const;
private:
	Rectangle* rect;
	Coordinates* coord;
};

}

#endif /* SRC_ARRANGEMENT_POSITIONEDRECTANGLE_H_ */