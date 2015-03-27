/*
 * The placement of a single Rectangle in the plane
 */

#ifndef SRC_ARRANGEMENT_POSITIONEDRECTANGLE_H_
#define SRC_ARRANGEMENT_POSITIONEDRECTANGLE_H_

#include "Coordinates.h"
#include "../Rectangle.h"
#include <memory>

namespace rechteckpackungen {

class PositionedRectangle {
public:
	PositionedRectangle(std::shared_ptr<Rectangle> rect, std::shared_ptr<Coordinates> coord);
	PositionedRectangle(std::shared_ptr<Rectangle> rect, int xMin, int yMin);
	PositionedRectangle(int xMin, int xMax, int yMin, int yMax);
	~PositionedRectangle();
	bool operator==(const PositionedRectangle& other);
	int getXMin() const;
	int getXMax() const;
	int getYMin() const;
	int getYMax() const;
	std::shared_ptr<Rectangle> getRectangle();
private:
	std::shared_ptr<Rectangle> rect;
	std::shared_ptr<Coordinates> coord;
};

}

#endif /* SRC_ARRANGEMENT_POSITIONEDRECTANGLE_H_ */
