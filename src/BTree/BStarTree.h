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
	BStarTree(std::shared_ptr<std::vector<Rectangle>> rectangles);
	BStarTree(const BStarTree& original);
	virtual ~BStarTree();
	Rectangle* getRectangle(BTreeNode* node) const;
	Rectangle* getRectangle(int index) const;
	std::shared_ptr<std::vector<Rectangle>> getRectangles() const;
private:
	std::shared_ptr<std::vector<Rectangle>> rectangles;
};

}

#endif /* SRC_BTREE_BSTARTREE_H_ */
