#ifndef SRC_RECTANGLE_H_
#define SRC_RECTANGLE_H_

#include <stdexcept>

namespace rechteckpackungen {

class Rectangle {
public:
	Rectangle();
	Rectangle(int width, int height);
	bool operator==(const Rectangle& other);
	void rotate();
	int getWidth() const;
	int getHeight() const;
	int getArea() const;
	/**
	 * Returns true if both width and height of this are at least equal to the width and height of other
	 */
	bool contains(const Rectangle& other) const;
private:
	int width;
	int height;
	bool rotated = false;
};

}

#endif
