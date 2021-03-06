/*
 * The placement of a single Rectangle in the plane
 */

#ifndef SRC_PLACEMENT_POSITIONEDRECTANGLE_H_
#define SRC_PLACEMENT_POSITIONEDRECTANGLE_H_

#include "Coordinates.h"
#include "../Rectangle.h"
#include <memory>

namespace rechteckpackungen {

class PositionedRectangle {
public:
	PositionedRectangle(Rectangle rect, Coordinates coord);
	PositionedRectangle(Rectangle rect, int xMin, int yMin);
	PositionedRectangle(int xMin, int xMax, int yMin, int yMax);
	~PositionedRectangle();
	bool operator==(const PositionedRectangle& other);
	int getXMin() const;
	int getXMax() const;
	int getYMin() const;
	int getYMax() const;
	Coordinates getTopRightCoordinates() const;
	Coordinates getBottomeLeftCoordinates() const;
	Rectangle getRectangle() const;
	bool contains(const PositionedRectangle& inner) const;
	bool contains(const Coordinates& point) const;
	bool isRotated() const;
	void rotate();
	void shift(const Coordinates offset);
private:
	Rectangle rect;
	Coordinates coord;
};

}

#endif /* SRC_PLACEMENT_POSITIONEDRECTANGLE_H_ */
