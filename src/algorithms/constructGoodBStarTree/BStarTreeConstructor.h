#ifndef RECHTECKPACKUNGEN_BSTARTREECONSTRUCTOR_H
#define RECHTECKPACKUNGEN_BSTARTREECONSTRUCTOR_H

#include "algorithms/placement2BStarTree/BStarTreeFactory.h"
#include "algorithms/improveBStarTree/BStarTreeImprover.h"
#include "algorithms/bStarTree2Placement/PlacementFactory.h"
#include "Rectangle.h"
#include "instance/Instance.h"
#include "BTree/BTreeNode.h"
#include "BTree/BStarTree.h"
#include <vector>
#include <memory>

namespace rechteckpackungen {
namespace constructGoodBStarTree {
class BStarTreeConstructor {
public:
    /**
     * Creates a BStarTree from an Instance.
     * This methods makes some attempts to deliver a tree that corresponds to a Placement with a small area.
     * However, good quality of the tree is not guaranteed.
     */
    BStarTree *create(Instance &instance);
};
}
}

#endif //RECHTECKPACKUNGEN_BSTARTREECONSTRUCTOR_H
