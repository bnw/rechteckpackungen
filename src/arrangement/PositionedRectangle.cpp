#include "PositionedRectangle.h"

namespace rechteckpackungen {

PositionedRectangle::PositionedRectangle(Rectangle *rect, Coordinates *coord) {
	this->rect = rect;
	this->coord = coord;
}

PositionedRectangle::PositionedRectangle(int xMin, int xMax, int yMin,
		int yMax) {
	int width = xMax - xMin;
	int height = yMax - yMin;
	this->rect = new Rectangle(width, height);
	this->coord = new Coordinates(xMin, yMin);
}

PositionedRectangle::~PositionedRectangle() {
	delete rect;
	delete coord;
}

int PositionedRectangle::getXMin() const {
	return this->coord->getX();
}

int PositionedRectangle::getXMax() const {
	return this->coord->getX() + this->rect->getWidth();
}

int PositionedRectangle::getYMin() const {
	return this->coord->getY();
}

int PositionedRectangle::getYMax() const {
	return this->coord->getY() + this->rect->getHeight();
}

bool PositionedRectangle::operator==(const PositionedRectangle& other) {
	return *rect == *(other.rect) && *coord == *(other.coord);
}

}
