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

bool BTreeNode::isAncestor(BTreeNode* pssibleAncestor){
	if(!hasParent()){
		return false;
	}
	if(getParent() == pssibleAncestor){
		return true;
	}
	return getParent()->isAncestor(pssibleAncestor);
}

bool BTreeNode::isRoot() const{
	return tree->getRoot() == this;
}

}
