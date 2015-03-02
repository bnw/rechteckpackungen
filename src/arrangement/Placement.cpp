#include "Placement.h"

namespace rechteckpackungen {

Placement::Placement(Rectangle *rect, Coordinates *coord){
	this->rect = rect;
	this->coord = coord;
}

int Placement::getXMin() const{
	return this->coord->getX();
}

int Placement::getYMin() const{
	return this->coord->getY();
}

bool Placement::operator==(const Placement& other){
	return *rect == *(other.rect) && *coord == *(other.coord);
}

}
