#ifndef SRC_BTREE_BSTARTREE_H_
#define SRC_BTREE_BSTARTREE_H_

#include "BTree/BTree.h"
#include "arrangement/Placement.h"
#include "Rectangle.h"
#include "algorithms/sortInt/BucketSort.h"
#include <vector>

namespace rechteckpackungen {

class BStarTree: public BTree {
public:
	BStarTree(std::vector<Rectangle*>* positionedRectangles);
	virtual ~BStarTree();
	Rectangle* getRectangle(BTreeNode* node);
	Rectangle* getRectangle(int index);
private:
	std::vector<Rectangle*>* rectangles;
};

}

#endif /* SRC_BTREE_BSTARTREE_H_ */
