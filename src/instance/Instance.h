#ifndef SRC_INSTANCE_INSTANCE_H_
#define SRC_INSTANCE_INSTANCE_H_

#include "arrangement/Placement.h"
#include "Rectangle.h"
#include <vector>

namespace rechteckpackungen {

class Instance {
public:
	Instance(Placement* area);
	~Instance();
	Placement* getArea();
	void addRectangle(Rectangle* rect);
private:
	Placement* area;
	std::vector<Rectangle*>* rectangles;
};

}

#endif
