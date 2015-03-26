#include "BTree.h"

namespace rechteckpackungen {

BTree::BTree(int size) {
	this->size = size;
	this->root = nullptr;
	nodes = std::vector<BTreeNode*>(size, nullptr);
	for (int i = 0; i < size; i++) {
		nodes.at(i) = new BTreeNode(this, i);
	}
}

BTree::~BTree() {
	for (auto node : nodes) {
		delete node;
	}
}

void BTree::setLeftChild(BTreeNode* parent, BTreeNode* leftChild) {
	if (leftChild->hasParent() || parent->hasLeftChild()) {
		throw new std::runtime_error(
				"Cannot set left child because parent->leftChild or leftChild->parent are occupied!");
	}
	leftChild->setParent(parent);
	parent->setLeftChild(leftChild);
}

void BTree::setRightChild(BTreeNode* parent, BTreeNode* rightChild) {
	if (rightChild->hasParent() || parent->hasRightChild()) {
		throw new std::runtime_error(
				"Cannot set left child because parent->rightChild or rightChild->parent are occupied!");
	}
	rightChild->setParent(parent);
	parent->setRightChild(rightChild);
}

void BTree::removeLeftChild(BTreeNode* parent){
	if(!parent->hasLeftChild()){
		throw new std::runtime_error("Was asked to remove left child, but no left child present.");
	}
	parent->getLeftChild()->setParent(nullptr);
	parent->setLeftChild(nullptr);
}

void BTree::removeRightChild(BTreeNode* parent){
	if(!parent->hasRightChild()){
		throw new std::runtime_error("Was asked to remove right child, but no right child present.");
	}
	parent->getRightChild()->setParent(nullptr);
	parent->setRightChild(nullptr);
}

BTreeNode* BTree::at(int i){
	return nodes.at(i);
}

BTreeNode* BTree::getRoot(){
	return root;
}

void BTree::setRoot(BTreeNode* node) {
	node->setParent(nullptr);
	root = node;
}

int BTree::getSize(){
	return size;
}

}
