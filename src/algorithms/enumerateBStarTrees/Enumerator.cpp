#include "Enumerator.h"

namespace rechteckpackungen {
namespace enumerateBStarTrees {

void Enumerator::forEachBStarTree(std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>>rectangles, const std::function<bool(BStarTree*)>& callback) {
	int size = rectangles->size();
	auto tree = BStarTree(rectangles);

	for (int rootIndex = 0; rootIndex < size; rootIndex++) {
		tree.setRoot(tree.at(rootIndex));
		if(!walkTree(&tree, rootIndex, 0, callback)) {
			break;
		}
	}
}

bool Enumerator::walkTree(BStarTree* tree, int rootIndex, int currentIndex, const std::function<bool(BStarTree*)>& callback) {
	int size = tree->getSize();
	if (currentIndex == size) {
		return callback(tree);
	}
	if (currentIndex == rootIndex) {
		return walkTree(tree, rootIndex, ++currentIndex, callback);
	}
	auto currentElement = tree->at(currentIndex);
	for (int i = 0; i < size; i++) {
		auto possibleParent = tree->at(i);
		if (possibleParent == currentElement || possibleParent->isAncestor(currentElement)) {
			continue;
		}
		if (!possibleParent->hasLeftChild()) {
			tree->setLeftChild(possibleParent, currentElement);
			if (!walkTree(tree, rootIndex, currentIndex + 1, callback)) {
				return false;
			}
			tree->removeLeftChild(possibleParent);
		}
		if (!possibleParent->hasRightChild()) {
			tree->setRightChild(possibleParent, currentElement);
			if (!walkTree(tree, rootIndex, currentIndex + 1, callback)) {
				return false;
			}
			tree->removeRightChild(possibleParent);
		}
	}
	return true;
}

}
}
