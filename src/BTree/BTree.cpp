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
		throw new std::runtime_error("Cannot set left child because parent->leftChild or leftChild->parent are occupied!");
	}
	leftChild->setParent(parent);
	parent->setLeftChild(leftChild);
}

void BTree::setRightChild(BTreeNode* parent, BTreeNode* rightChild) {
	if (rightChild->hasParent() || parent->hasRightChild()) {
		throw new std::runtime_error("Cannot set left child because parent->rightChild or rightChild->parent are occupied!");
	}
	rightChild->setParent(parent);
	parent->setRightChild(rightChild);
}

BTreeNode* BTree::removeLeftChild(BTreeNode* parent) {
	if (!parent->hasLeftChild()) {
		throw new std::runtime_error("Was asked to remove left child, but no left child present.");
	}
	auto leftChild = parent->getLeftChild();
	leftChild->setParent(nullptr);
	parent->setLeftChild(nullptr);
	return leftChild;
}

BTreeNode* BTree::removeRightChild(BTreeNode* parent) {
	if (!parent->hasRightChild()) {
		throw new std::runtime_error("Was asked to remove right child, but no right child present.");
	}
	auto rightChild = parent->getRightChild();
	rightChild->setParent(nullptr);
	parent->setRightChild(nullptr);
	return rightChild;
}

void BTree::removeChild(BTreeNode* parent, BTreeNode* child) {
	if (parent->hasRightChild() && parent->getRightChild() == child) {
		removeRightChild(parent);
		return;
	}
	if (parent->hasLeftChild() && parent->getLeftChild() == child) {
		removeLeftChild(parent);
		return;
	}
	throw new std::runtime_error("Was asked to remove child from parent, but child is neither left nor right child of parent.");
}

void BTree::replaceChild(BTreeNode* parent, BTreeNode* child, BTreeNode* replacement) {
	if (parent->hasRightChild() && parent->getRightChild() == child) {
		removeRightChild(parent);
		setRightChild(parent, replacement);
		return;
	}
	if (parent->hasLeftChild() && parent->getLeftChild() == child) {
		removeLeftChild(parent);
		setLeftChild(parent, replacement);
		return;
	}
}

void BTree::pushOrphant(BTreeNode* parent, BTreeNode* orphant) {
	if (!parent->hasLeftChild()) {
		setLeftChild(parent, orphant);
	} else if (!parent->hasRightChild()) {
		setRightChild(parent, orphant);
	} else {
		auto newOrphant = parent->getLeftChild();
		removeLeftChild(parent);
		setLeftChild(parent, orphant);
		pushOrphant(parent->getRightChild(), newOrphant);
	}
}

void BTree::remove(BTreeNode* node) {
	auto parent = node->getParent();
	if (!node->hasChildren()) { // has no children
		if (node->isRoot()) {
			throw new std::runtime_error("Cannot remove root without children");
		} else {
			removeChild(parent, node);
		}
	} else if (node->hasRightChild() && node->hasLeftChild()) { // has two children
		auto replacement = node->getRightChild();
		removeRightChild(node);
		auto formerLeftChild = node->getLeftChild();
		removeLeftChild(node);
		if (node->isRoot()) {
			setRoot(replacement);
		} else {
			replaceChild(parent, node, replacement);
		}
		pushOrphant(replacement, formerLeftChild);
	} else { // has exactly 1 child
		BTreeNode* child;
		if (node->hasLeftChild()) {
			child = node->getLeftChild();
		} else {
			child = node->getRightChild();
		}
		removeChild(node, child);
		if (node->isRoot()) {
			removeChild(node, child);
			setRoot(child);
		} else {
			replaceChild(parent, node, child);
		}
	}
}

BTreeNode* BTree::at(int i) {
	return nodes.at(i);
}

BTreeNode* BTree::getRoot() {
	return root;
}

void BTree::setRoot(BTreeNode* node) {
	node->setParent(nullptr);
	root = node;
}

int BTree::getSize() {
	return size;
}

}
