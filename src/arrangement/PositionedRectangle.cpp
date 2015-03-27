#include "PositionedRectangle.h"

namespace rechteckpackungen {

PositionedRectangle::PositionedRectangle(std::shared_ptr<Rectangle> rect, std::shared_ptr<Coordinates> coord) :
		rect(rect), coord(coord) {
}

PositionedRectangle::PositionedRectangle(std::shared_ptr<Rectangle> rect, int xMin, int yMin) :
		rect(rect) {
	coord = std::shared_ptr<Coordinates>(new Coordinates(xMin, yMin));
}

PositionedRectangle::PositionedRectangle(int xMin, int xMax, int yMin, int yMax) {
	int width = xMax - xMin;
	int height = yMax - yMin;
	rect = std::shared_ptr<Rectangle>(new Rectangle(width, height));
	coord = std::shared_ptr<Coordinates>(new Coordinates(xMin, yMin));
}

PositionedRectangle::~PositionedRectangle() {
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

std::shared_ptr<Rectangle> PositionedRectangle::getRectangle() {
	return this->rect;
}

bool PositionedRectangle::operator==(const PositionedRectangle& other) {
	return *rect == *(other.rect) && *coord == *(other.coord);
}

bool PositionedRectangle::contains(const PositionedRectangle& inner) const{
	return contains(Coordinates(inner.getXMin(), inner.getYMin())) && contains(Coordinates(inner.getXMax(), inner.getYMax()));
}

bool PositionedRectangle::contains(const Coordinates& point) const{
	return getYMin() <= point.getY() && getYMax() >= point.getY() && getXMin() <= point.getX() && getXMax() >= point.getX();
}

}
