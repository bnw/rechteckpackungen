#ifndef SRC_INSTANCE_INSTANCE_H_
#define SRC_INSTANCE_INSTANCE_H_

#include "arrangement/PositionedRectangle.h"
#include "Rectangle.h"
#include <vector>
#include <memory>

namespace rechteckpackungen {

class Instance {
public:
	Instance(std::shared_ptr<PositionedRectangle> area);
	~Instance();
	bool operator==(const Instance& other);
	std::shared_ptr<PositionedRectangle> getArea();
	void addRectangle(std::shared_ptr<Rectangle> rect);
	std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>> getRectangles();
private:
	std::shared_ptr<PositionedRectangle> area;
	std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>> rectangles;
};

}

#endif
