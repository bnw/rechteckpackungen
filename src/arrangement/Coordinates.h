#ifndef SRC_ARRANGEMENT_COORDINATES_H_
#define SRC_ARRANGEMENT_COORDINATES_H_

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
private:
	int x;
	int y;
};

}

#endif
