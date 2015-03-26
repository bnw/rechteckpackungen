#include "Enumerator.h"

namespace rechteckpackungen {
namespace enumerateBStarTrees {

void Enumerator::forEachBStarTree(std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>> rectangles, const std::function<void(BStarTree*)>& callback) {
	int size = rectangles->size();
	auto tree = BStarTree(rectangles);

	for (int rootIndex = 0; rootIndex < size; rootIndex++) {
		tree.setRoot(tree.at(rootIndex));
		walkTree(&tree, rootIndex, 0, callback);
	}
}

void Enumerator::walkTree(BStarTree* tree, int rootIndex, int currentIndex, const std::function<void(BStarTree*)>& callback) {
	int size = tree->getSize();
	if (currentIndex == size) {
		callback(tree);
		return;
	}
	if (currentIndex == rootIndex) {
		walkTree(tree, rootIndex, ++currentIndex, callback);
		return;
	}
	auto currentElement = tree->at(currentIndex);
	for (int i = 0; i < size; i++) {
		auto possibleParent = tree->at(i);
		if(possibleParent == currentElement || possibleParent->isAncestor(currentElement)){
			continue;
		}
		if (!possibleParent->hasLeftChild()) {
			tree->setLeftChild(possibleParent, currentElement);
			walkTree(tree, rootIndex, currentIndex + 1, callback);
			tree->removeLeftChild(possibleParent);
		}
		if (!possibleParent->hasRightChild()) {
			tree->setRightChild(possibleParent, currentElement);
			walkTree(tree, rootIndex, currentIndex + 1, callback);
			tree->removeRightChild(possibleParent);
		}
	}
}

}
}
