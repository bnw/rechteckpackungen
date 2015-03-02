#include "Placement.h"

namespace rechteckpackungen {

Placement::Placement(Rectangle *rect, Coordinates *coord){
	this->rect = rect;
	this->coord = coord;
}

bool Placement::operator==(const Placement& other){
	return *rect == *(other.rect) && *coord == *(other.coord);
}

}
