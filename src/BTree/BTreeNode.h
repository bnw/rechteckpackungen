#ifndef SRC_BTREE_BTREENODE_H_
#define SRC_BTREE_BTREENODE_H_

#include "BTree/BTree.h"
#include <stdexcept>

namespace rechteckpackungen {

class BTree;

class BTreeNode {
public:
	BTreeNode(BTree* tree, int index);
	virtual ~BTreeNode();
	void setParent(BTreeNode* parent);
	BTreeNode* getParent();
	BTreeNode* getLeftChild();
	BTreeNode* getRightChild();
	int getIndex();
	bool hasParent();
	bool hasLeftChild();
	bool hasRightChild();
	bool hasChildren();
	void setLeftChild(BTreeNode* leftChild);
	void setRightChild(BTreeNode* rightChild);
	void removeChild(BTreeNode* child);
private:
	BTree* tree;
	BTreeNode* leftChild;
	BTreeNode* rightChild;
	BTreeNode* parent;
	/*
	 * Index, under which this node is accessible thru in tree->at(index).
	 */
	int index;
};

}

#endif /* SRC_BTREE_BTREENODE_H_ */
