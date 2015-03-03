#include "Placement.h"

namespace rechteckpackungen {

Placement::Placement(Rectangle *rect, Coordinates *coord){
	this->rect = rect;
	this->coord = coord;
}

Placement::Placement(int xMin, int xMax, int yMin, int yMax){
	int width = xMax - xMin;
	int height = yMax - yMin;
	this->rect = new Rectangle(width, height);
	this->coord = new Coordinates(xMin, yMin);
}

Placement::~Placement(){
	delete rect;
	delete coord;
}

int Placement::getXMin() const{
	return this->coord->getX();
}

int Placement::getXMax() const{
	return this->coord->getX() + this->rect->getWidth();
}

int Placement::getYMin() const{
	return this->coord->getY();
}

int Placement::getYMax() const{
	return this->coord->getY() + this->rect->getHeight();
}

bool Placement::operator==(const Placement& other){
	return *rect == *(other.rect) && *coord == *(other.coord);
}

}
