#ifndef SRC_BTREE_BSTARTREE_H_
#define SRC_BTREE_BSTARTREE_H_

#include "BTree/BTree.h"
#include "arrangement/Placement.h"
#include "Rectangle.h"
#include "algorithms/sortInt/BucketSort.h"
#include <vector>
#include <memory>

namespace rechteckpackungen {

class BStarTree: public BTree {
public:
	BStarTree(std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>> rectangles);
	virtual ~BStarTree();
	std::shared_ptr<Rectangle> getRectangle(BTreeNode* node);
	std::shared_ptr<Rectangle> getRectangle(int index);
private:
	std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>> rectangles;
};

}

#endif /* SRC_BTREE_BSTARTREE_H_ */
