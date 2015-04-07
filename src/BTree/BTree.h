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
	BTreeNode* removeLeftChild(BTreeNode* parent);
	BTreeNode* removeRightChild(BTreeNode* parent);
	void removeChild(BTreeNode* parent, BTreeNode* child);
	void pushOrphant(BTreeNode* parent, BTreeNode* orphant);
	void replaceChild(BTreeNode* parent, BTreeNode* child, BTreeNode* replacement);
	void remove(BTreeNode* node);
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
