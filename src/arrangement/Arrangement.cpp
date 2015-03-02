#include "Arrangement.h"

namespace rechteckpackungen {

Arrangement::Arrangement() {
	placements = new std::vector<Placement*>;
}

Arrangement::~Arrangement() {
	delete placements;
}

bool Arrangement::operator==(const Arrangement& other) {
	if(placements->size() != other.placements->size()){
		return false;
	}
	for(int i = 0; i < placements->size(); i++){
		auto ownPlacement = (Placement*) placements->at(i);
		auto otherPlacement = (Placement*) other.placements->at(i);
		if(!(*ownPlacement == *otherPlacement)){
			return false;
		}
	}
	return true;
}

void Arrangement::add(Placement* placement) {
	placements->push_back(placement);
}

}

