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

BTreeNode* BTree::at(int i){
	return nodes.at(i);
}

BTreeNode* BTree::getRoot(){
	return root;
}

void BTree::setRoot(BTreeNode* node) {
	if(root != nullptr){
		throw new std::runtime_error("Cannot set root because root was already set");
	}
	node->setParent(nullptr);
	root = node;
}

}
