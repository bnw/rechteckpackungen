#ifndef SRC_BTREE_BTREENODE_H_
#define SRC_BTREE_BTREENODE_H_

#include <stdexcept>

namespace rechteckpackungen {

class BTreeNode {
public:
	BTreeNode(int index);
	virtual ~BTreeNode();
	void setParent(BTreeNode* parent);
	BTreeNode* getParent() const;
	BTreeNode* getLeftChild() const;
	BTreeNode* getRightChild() const;
	BTreeNode* getClosestParentOfWhichIAmLeft() const;
	int getIndex() const;
	bool hasParent() const;
	bool hasLeftChild() const;
	bool hasRightChild() const;
	bool hasChildren() const;
	bool isAncestor(BTreeNode* possibleAncestor) const;
	bool isRoot() const;
	void setLeftChild(BTreeNode* leftChild);
	void setRightChild(BTreeNode* rightChild);

private:
	BTreeNode* leftChild;
	BTreeNode* rightChild;
	BTreeNode* parent;
	/*
	 * Index, under which this node is accessible thru tree->at(index).
	 */
	int index;
};

}

#endif /* SRC_BTREE_BTREENODE_H_ */
