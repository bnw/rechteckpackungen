#ifndef SRC_BTREE_BTREE_H_
#define SRC_BTREE_BTREE_H_

#include "BTree/BTreeNode.h"
#include "placement/Placement.h"
#include <vector>
#include <stdexcept>

namespace rechteckpackungen {

class BTree {
public:
	BTree(unsigned size);
	BTree(Placement* placement);
	BTree(const BTree& original);
	virtual ~BTree();
	void setLeftChild(BTreeNode* parent, BTreeNode* leftChild);
	void setRightChild(BTreeNode* parent, BTreeNode* rightChild);
	/**
	 * If parent has no left child, squeezeInLeftChild is the same as setLeftChild.
	 * Otherwise, the left child of parent will become the left child of leftChild and
	 * leftChild will become the left child of parent.
	 */
	void squeezeInLeftChild(BTreeNode* parent, BTreeNode* leftChild);
	void squeezeInRightChild(BTreeNode* parent, BTreeNode* leftChild);
	BTreeNode* removeLeftChild(BTreeNode* parent);
	BTreeNode* removeRightChild(BTreeNode* parent);
	/**
	 * Convenient method to remove a child from its parent if you don't know if its
	 * the left or right child.
	 */
	void removeChild(BTreeNode* parent, BTreeNode* child);
	/**
	 * Convenient method to detach child from parent and insert replacement at the former position of child.
	 */
	void replaceChild(BTreeNode* parent, BTreeNode* child, BTreeNode* replacement);
	/**
	 * Removes node from the tree by detaching node from its parent (if any) and node's children (if any) from itself.
	 * It then adds the now orphan children back to the tree at similar positions as before.
	 * Complexity: O(h) where h is the height of the tree
	 */
	void remove(BTreeNode* node);
	BTreeNode* at(int i) const;
	BTreeNode* getRoot() const;
	const std::vector<BTreeNode*>& getNodes() const;
	void setRoot(BTreeNode* node);
	bool hasRoot() const;
	bool isRoot(BTreeNode* node) const;
	unsigned getSize() const;
protected:
	/**
	 * Try to make orphan the child of parent (left or right).
	 * If parent already has two children:
	 * 		- make orphan left child of parent
	 * 		- iterate by pushing the new orphan (former left child of parent) to the right child of parent
	 */
	void pushOrphan(BTreeNode* parent, BTreeNode* orphan);
	std::vector<BTreeNode*> nodes;
	BTreeNode* root;
private:
	unsigned size;
};

}

#endif
