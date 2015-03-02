#ifndef SRC_ARRANGEMENT_COORDINATES_H_
#define SRC_ARRANGEMENT_COORDINATES_H_

namespace rechteckpackungen {

class Coordinates {
public:
	Coordinates();
	Coordinates(int x, int y);
	bool operator==(const Coordinates& other);
private:
	int x;
	int y;
};

}

#endif /* SRC_ARRANGEMENT_COORDINATES_H_ */
