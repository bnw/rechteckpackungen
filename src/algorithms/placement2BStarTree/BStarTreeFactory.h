#ifndef SRC_ALGORITHMS_PLACEMENT2BSTARTREE_BSTARTREEFACTORY_H_
#define SRC_ALGORITHMS_PLACEMENT2BSTARTREE_BSTARTREEFACTORY_H_

#include "BTree/BStarTree.h"
#include "arrangement/Placement.h"

namespace rechteckpackungen {
namespace placement2BStarTree {

class BStarTreeFactory {
public:
	BStarTree* create(Placement *placement);
private:
	void buildTreeRecursively(BTreeNode* rootNode, std::vector<std::vector<int>>& xBuckets, BStarTree* tree);
};

}
}

#endif /* SRC_ALGORITHMS_PLACEMENT2BSTARTREE_BSTARTREEFACTORY_H_ */
