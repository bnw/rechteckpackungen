#ifndef SRC_INSTANCE_INSTANCE_H_
#define SRC_INSTANCE_INSTANCE_H_

#include "arrangement/PositionedRectangle.h"
#include "Rectangle.h"
#include <vector>

namespace rechteckpackungen {

class Instance {
public:
	Instance(PositionedRectangle* area);
	~Instance();
	bool operator==(const Instance& other);
	PositionedRectangle* getArea();
	void addRectangle(Rectangle* rect);
	std::vector<Rectangle*>* getRectangles();
private:
	PositionedRectangle* area;
	std::vector<Rectangle*>* rectangles;
};

}

#endif
