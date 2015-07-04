#ifndef SRC_ALGORITHMS_IMPROVEBSTARTREE_BSTARTREEIMPROVER_H_
#define SRC_ALGORITHMS_IMPROVEBSTARTREE_BSTARTREEIMPROVER_H_

#include "BTree/BStarTree.h"
#include "BTree/BTreeNode.h"
#include "algorithms/bStarTree2Placement/PlacementFactory.h"
#include "algorithms/enumerateSubsets/Enumerator.h"
#include "algorithms/enumerateBStarTreeMutations/Enumerator.h"
#include "instance/Instance.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <limits>

namespace rechteckpackungen {
namespace improveBStarTree {

class BStarTreeImprover {
public:
	/**
	 * If noTreeMutation == true, we will not move rectangles around the tree (see forEachMovement).
	 * If noRotation == true, we will not rotate the rectangles (see forEachOrientation).
	 */
	BStarTreeImprover(bool noRotation = false, bool noTreeMutation = false) :
			noRotation(noRotation),
			noTreeMutation(noTreeMutation) { }

/**
	 * @param instance Returned tree (if any) is guaranteed to fit in the bounds of instance.
	 * @param k Number of nodes that can be modified to improve the tree.
	 * @return Returns nullptr or pointer to BStarTree. Caller should consider himself owner of the tree.
	 */
	BStarTree *improve(const BStarTree &tree, const Instance &instance, unsigned numberOfNodesThatCanBeMutated) const;

protected:
	bool noRotation;
	bool noTreeMutation;

	void challengeOptimum(BStarTree *&currentOptimalTree, int &currentOptimalTreeArea, const BStarTree &challenger,
			bStarTree2Placement::PlacementFactory &placementFactory, const Instance &instance) const;
};

}
}

#endif /* SRC_ALGORITHMS_IMPROVEBSTARTREE_BSTARTREEIMPROVER_H_ */
