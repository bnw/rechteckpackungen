#ifndef SRC_RECTANGLE_H_
#define SRC_RECTANGLE_H_

namespace rechteckpackungen {

class Rectangle {
public:
	Rectangle(int width, int height);
	void rotate();
	int getWidth();
	int getHeight();
private:
	int width;
	int height;
	bool rotated = false;
};

}

#endif
