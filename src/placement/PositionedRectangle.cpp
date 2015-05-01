#include "PositionedRectangle.h"

namespace rechteckpackungen {

PositionedRectangle::PositionedRectangle(Rectangle rect, Coordinates coord) :
		rect(rect), coord(coord) {
}

PositionedRectangle::PositionedRectangle(Rectangle rect, int xMin, int yMin) :
		rect(rect) {
	coord = Coordinates(xMin, yMin);
}

PositionedRectangle::PositionedRectangle(int xMin, int xMax, int yMin, int yMax) {
	int width = xMax - xMin;
	int height = yMax - yMin;
	rect = Rectangle(width, height);
	coord = Coordinates(xMin, yMin);
}

PositionedRectangle::~PositionedRectangle() {
}

int PositionedRectangle::getXMin() const {
	return this->coord.getX();
}

int PositionedRectangle::getXMax() const {
	return this->coord.getX() + this->rect.getWidth();
}

int PositionedRectangle::getYMin() const {
	return this->coord.getY();
}

int PositionedRectangle::getYMax() const {
	return this->coord.getY() + this->rect.getHeight();
}

Coordinates PositionedRectangle::getTopRightCoordinates() const{
	return Coordinates(getXMax(), getYMax());
}

Rectangle PositionedRectangle::getRectangle() {
	return rect;
}

bool PositionedRectangle::operator==(const PositionedRectangle& other) {
	return rect == other.rect && coord == other.coord;
}

bool PositionedRectangle::contains(const PositionedRectangle& inner) const{
	return contains(Coordinates(inner.getXMin(), inner.getYMin())) && contains(Coordinates(inner.getXMax(), inner.getYMax()));
}

bool PositionedRectangle::contains(const Coordinates& point) const{
	return getYMin() <= point.getY() && getYMax() >= point.getY() && getXMin() <= point.getX() && getXMax() >= point.getX();
}

bool PositionedRectangle::isRotated() const{
	return rect.isRotated();
}

void PositionedRectangle::rotate() {
	rect.rotate();
}

}
