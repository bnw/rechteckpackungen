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
	void removeLeftChild(BTreeNode* parent);
	void removeRightChild(BTreeNode* parent);
	BTreeNode* at(int i);
	BTreeNode* getRoot();
	void setRoot(BTreeNode* node);
	int getSize();
protected:
	std::vector<BTreeNode*> nodes;
	BTreeNode* root;
private:
	int size;
};

}

#endif
