#ifndef SRC_ALGORITHMS_PLACEMENT2BSTARTREE_BSTARTREEFACTORY_H_
#define SRC_ALGORITHMS_PLACEMENT2BSTARTREE_BSTARTREEFACTORY_H_

#include "BTree/BStarTree.h"
#include "placement/Placement.h"
#include <stdexcept>

namespace rechteckpackungen {
namespace placement2BStarTree {

class BStarTreeFactory {
public:
	/**
	 * Complexity: O(n)
	 */
	BStarTree* create(Placement *placement);
private:
	/**
	 * Complexity: O(1) + recursion
	 */
	void buildTreeRecursively(BTreeNode* rootNode, std::vector<std::vector<int>>& xBuckets, BStarTree* tree, std::vector<PositionedRectangle>* positionedRectangles);
};

}
}

#endif /* SRC_ALGORITHMS_PLACEMENT2BSTARTREE_BSTARTREEFACTORY_H_ */
