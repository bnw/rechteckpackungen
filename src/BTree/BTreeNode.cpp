#include "BTreeNode.h"

namespace rechteckpackungen {

BTreeNode::BTreeNode(int index) :
		index(index) {
	leftChild = nullptr;
	rightChild = nullptr;
	parent = nullptr;
}

BTreeNode::~BTreeNode() {
}

void BTreeNode::setLeftChild(BTreeNode* leftChild) {
	this->leftChild = leftChild;
}

void BTreeNode::setRightChild(BTreeNode* rightChild) {
	this->rightChild = rightChild;
}

void BTreeNode::setParent(BTreeNode* parent) {
	this->parent = parent;
}

int BTreeNode::getIndex() const {
	return index;
}

BTreeNode* BTreeNode::getParent() const {
	return parent;
}

BTreeNode* BTreeNode::getLeftChild() const {
	return leftChild;
}

BTreeNode* BTreeNode::getRightChild() const {
	return rightChild;
}

BTreeNode* BTreeNode::getClosestParentOfWhichIAmLeft() const {
	if (!hasParent()) {
		return NULL;
	}
	if (getParent()->getLeftChild() == this) {
		return getParent();
	}
	return getParent()->getClosestParentOfWhichIAmLeft();
}

bool BTreeNode::hasParent() const {
	return getParent() != nullptr;
}

bool BTreeNode::hasLeftChild() const {
	return getLeftChild() != nullptr;
}

bool BTreeNode::hasRightChild() const {
	return getRightChild() != nullptr;
}

bool BTreeNode::hasChildren() const {
	return hasLeftChild() || hasRightChild();
}

bool BTreeNode::isAncestor(BTreeNode* pssibleAncestor) const {
	if (!hasParent()) {
		return false;
	}
	if (getParent() == pssibleAncestor) {
		return true;
	}
	return getParent()->isAncestor(pssibleAncestor);
}

}
