#ifndef SRC_BTREE_BTREENODE_H_
#define SRC_BTREE_BTREENODE_H_

#include <stdexcept>

namespace rechteckpackungen {

class BTreeNode {
public:
	BTreeNode(unsigned index);
	virtual ~BTreeNode();
	void setParent(BTreeNode* parent);
	BTreeNode* getParent() const;
	BTreeNode* getLeftChild() const;
	BTreeNode* getRightChild() const;
	BTreeNode* getClosestParentOfWhichIAmLeft() const;
	unsigned getIndex() const;
	bool hasParent() const;
	bool hasLeftChild() const;
	bool hasRightChild() const;
	bool hasChildren() const;
	bool isAncestor(BTreeNode* possibleAncestor) const;
	void setLeftChild(BTreeNode* leftChild);
	void setRightChild(BTreeNode* rightChild);

private:
	BTreeNode* leftChild;
	BTreeNode* rightChild;
	BTreeNode* parent;
	/*
	 * Index, under which this node is accessible thru tree->at(index).
	 */
	unsigned index;
};

}

#endif /* SRC_BTREE_BTREENODE_H_ */
