#ifndef SRC_ALGORITHMS_BSTARTTREE2PLACEMENT_PLACEMENTFACTORY_H_
#define SRC_ALGORITHMS_BSTARTTREE2PLACEMENT_PLACEMENTFACTORY_H_

#include "BTree/BStarTree.h"
#include "arrangement/Placement.h"


namespace rechteckpackungen {
namespace bStarTree2Placement {

class PlacementFactory {
public:
	Placement* create(BStarTree* tree);
};

}
}

#endif /* SRC_ALGORITHMS_BSTARTTREE2PLACEMENT_PLACEMENTFACTORY_H_ */
