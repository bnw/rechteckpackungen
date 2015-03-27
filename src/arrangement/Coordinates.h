#ifndef SRC_ARRANGEMENT_COORDINATES_H_
#define SRC_ARRANGEMENT_COORDINATES_H_

namespace rechteckpackungen {

class Coordinates {
public:
	Coordinates();
	Coordinates(int x, int y);
	bool operator==(const Coordinates& other);
	int getX() const;
	int getY() const;
private:
	int x;
	int y;
};

}

#endif
