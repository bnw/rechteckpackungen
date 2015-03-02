#include "Arrangement.h"

namespace rechteckpackungen {

Arrangement::Arrangement() {
	placements = new std::vector<Placement*>;
}

Arrangement::~Arrangement() {
	for(auto placement : *placements){
		delete placement;
	}
	delete placements;
}

bool Arrangement::operator==(const Arrangement& other) {
	if (placements->size() != other.placements->size()) {
		return false;
	}
	for (int i = 0; i < placements->size(); i++) {
		auto ownPlacement = (Placement*) placements->at(i);
		auto otherPlacement = (Placement*) other.placements->at(i);
		if (!(*ownPlacement == *otherPlacement)) {
			return false;
		}
	}
	return true;
}

bool comparePlacementsByXMin(const Placement* a, const Placement* b){ return a->getXMin() < b->getXMin(); }
void Arrangement::sortPlacementsByXMin() {
	sort(placements->begin(), placements->end(), comparePlacementsByXMin);
}

std::vector<Placement*>* Arrangement::getPlacements() {
	return placements;
}

void Arrangement::add(Placement* placement) {
	placements->push_back(placement);
}

}

