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
	BStarTreeImprover() {}

	/**
	 * @param instance Returned tree (if any) is guaranteed to fit in the bounds of instance.
	 * @param k Number of nodes that can be modified to improve the tree.
	 * @return Returns nullptr or pointer to BStarTree. Caller should consider himself owner of the tree.
	 */
	BStarTree* improve(const BStarTree& tree, const Instance& instance, unsigned k) const;
protected:
	void challengeOptimum(BStarTree *&currentOptimalTree, int &currentOptimalTreeArea, const BStarTree &challenger,
			bStarTree2Placement::PlacementFactory &placementFactory, const Instance &instance) const;
};

}
}

#endif /* SRC_ALGORITHMS_IMPROVEBSTARTREE_BSTARTREEIMPROVER_H_ */
