#ifndef SRC_INSTANCE_INSTANCE_H_
#define SRC_INSTANCE_INSTANCE_H_

#include "arrangement/PositionedRectangle.h"
#include "Rectangle.h"
#include <vector>
#include <memory>

namespace rechteckpackungen {

class Instance {
public:
	Instance(std::shared_ptr<PositionedRectangle> bounds);
	~Instance();
	bool operator==(const Instance& other);
	std::shared_ptr<PositionedRectangle> getBounds();
	void addRectangle(std::shared_ptr<Rectangle> rect);
	std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>> getRectangles();
	/**
	 * Calculates the sum of the area of all rectangles
	 */
	int getAreaSum() const;
private:
	std::shared_ptr<PositionedRectangle> bounds;
	std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>> rectangles;
};

}

#endif
