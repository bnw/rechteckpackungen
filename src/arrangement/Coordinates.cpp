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

bool Coordinates::operator==(const Coordinates& other) {
	return x == other.x && y == other.y;
}

}
