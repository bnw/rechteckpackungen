#ifndef SRC_BTREE_BTREE_H_
#define SRC_BTREE_BTREE_H_

#include "arrangement/Placement.h"
#include "BTree/BTreeNode.h"
#include <vector>
#include <stdexcept>

namespace rechteckpackungen {

class BTreeNode;

class BTree {
public:
	BTree(int size);
	BTree(Placement* placement);
	virtual ~BTree();
	void setLeftChild(BTreeNode* parent, BTreeNode* leftChild);
	void setRightChild(BTreeNode* parent, BTreeNode* rightChild);
	BTreeNode* at(int i);
	BTreeNode* getRoot();
protected:
	void setRoot(BTreeNode* node);
	std::vector<BTreeNode*> nodes;
	BTreeNode* root;
private:
	int size;
};

}

#endif
