#include "BTreeNode.h"

namespace rechteckpackungen {

BTreeNode::BTreeNode(BTree* tree, int index) :
		tree(tree), index(index) {
	leftChild = nullptr;
	rightChild = nullptr;
	parent = nullptr;
}

BTreeNode::~BTreeNode() {
	// TODO Auto-generated destructor stub
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

int BTreeNode::getIndex(){
	return index;
}

BTreeNode* BTreeNode::getParent() {
	return parent;
}

BTreeNode* BTreeNode::getLeftChild() {
	return leftChild;
}

BTreeNode* BTreeNode::getRightChild() {
	return rightChild;
}

BTreeNode* BTreeNode::getClosestParentOfWhichIAmLeft(){
	if(!hasParent()){
		return NULL;
	}
	if(getParent()->getLeftChild() == this){
		return getParent();
	}
	return getParent()->getClosestParentOfWhichIAmLeft();
}

bool BTreeNode::hasParent() {
	return getParent() != nullptr;
}

bool BTreeNode::hasLeftChild() {
	return getLeftChild() != nullptr;
}

bool BTreeNode::hasRightChild() {
	return getRightChild() != nullptr;
}

bool BTreeNode::hasChildren(){
	return hasLeftChild() || hasRightChild();
}

void BTreeNode::removeChild(BTreeNode* child) {
	if (leftChild == child) {
		leftChild = nullptr;
	} else if (rightChild == child) {
		rightChild = nullptr;
	} else {
		throw new std::runtime_error(
				"Integrity error. Was asked to remove Child that was not there.");
	}
}

}
