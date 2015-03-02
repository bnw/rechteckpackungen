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
private:
	int width;
	int height;
	bool rotated = false;
};

}

#endif
