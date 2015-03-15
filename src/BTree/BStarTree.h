#ifndef SRC_BTREE_BSTARTREE_H_
#define SRC_BTREE_BSTARTREE_H_

#include "BTree/BTree.h"
#include "arrangement/Placement.h"
#include "arrangement/PositionedRectangle.h"
#include "algorithms/sortInt/BucketSort.h"
#include <vector>

namespace rechteckpackungen {

class BStarTree: public BTree {
public:
	BStarTree(std::vector<PositionedRectangle*>* positionedRectangles);
	virtual ~BStarTree();
	PositionedRectangle* getPositionedRectangle(BTreeNode* node);
	PositionedRectangle* getPositionedRectangle(int index);
private:
	std::vector<PositionedRectangle*>* positionedRectangles;
};

}

#endif /* SRC_BTREE_BSTARTREE_H_ */
