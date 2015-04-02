#include "Rectangle.h"

namespace rechteckpackungen {

Rectangle::Rectangle(int width, int height) {
	if(width < 0 || height < 0){
		throw std::runtime_error(
						"Width and height cannot be negative");
	}
	this->width = width;
	this->height = height;
}

Rectangle::Rectangle() {
	this->width = 0;
	this->height = 0;
}

bool Rectangle::operator==(const Rectangle& other){
	return this->getHeight() == other.getHeight() && this->getWidth() == other.getWidth();
}

void Rectangle::rotate() {
	rotated = !rotated;
}

int Rectangle::getWidth() const {
	if (rotated) {
		return height;
	}
	return width;
}

int Rectangle::getHeight() const {
	if (rotated) {
		return width;
	}
	return height;
}

int Rectangle::getArea() const{
	return width * height;
}

bool Rectangle::contains(const Rectangle& other) const{
	return getWidth() >= other.getWidth() && getHeight() >= other.getHeight();
}

}
