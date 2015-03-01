#include "Rectangle.h"

namespace rechteckpackungen {

Rectangle::Rectangle(int width, int height) {
	this->width = width;
	this->height = height;
}

void Rectangle::rotate() {
	rotated = !rotated;
}

int Rectangle::getWidth() {
	if (rotated) {
		return height;
	}
	return width;
}

int Rectangle::getHeight() {
	if (rotated) {
		return width;
	}
	return height;
}

}
