#include "Coordinates.h"

namespace rechteckpackungen {

Coordinates::Coordinates(int x, int y) {
	this->x = x;
	this->y = y;
}

Coordinates::Coordinates() {
	this->x = 0;
	this->y = 0;
}

int Coordinates::getX() const{
	return x;
}

int Coordinates::getY() const{
	return y;
}

bool Coordinates::operator==(const Coordinates& other) {
	return x == other.x && y == other.y;
}

bool Coordinates::areWithin(const Rectangle& bounds) const{
	return getX() <= bounds.getWidth() && getY() <= bounds.getHeight();
}

void Coordinates::shift(const Coordinates offset) {
	x += offset.getX();
	y += offset.getY();
}

}
