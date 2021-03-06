#ifndef SRC_PLACEMENT_COORDINATES_H_
#define SRC_PLACEMENT_COORDINATES_H_

#include <memory>
#include "Rectangle.h"

namespace rechteckpackungen {

class Coordinates {
public:
	typedef std::shared_ptr<Coordinates> ptr;
	Coordinates();
	Coordinates(int x, int y);
	bool operator==(const Coordinates& other);
	int getX() const;
	int getY() const;
	bool areWithin(const Rectangle& bounds) const;
	void shift(const Coordinates offset);
private:
	int x;
	int y;
};

}

#endif
