#include "Enumerator.h"

namespace rechteckpackungen {
namespace enumerateBStarTreeMutations {

void Enumerator::forEachMutation(const BStarTree& tree, const std::vector<BTreeNode*>& subset, Enumerator::callbackType callback) const {
	auto workingTree = BStarTree(tree);
	walkSubset(workingTree, subset.begin(), subset, callback);
}

void Enumerator::forEachOrientation(Rectangle& rectangle, const std::function<void()>& callback) const {
	callback();
	if (!rectangle.isSquare()) {
		rectangle.rotate();
		callback();
		rectangle.rotate(); //rotate back
	}
}

void Enumerator::forEachSwap(const std::vector<Rectangle>::iterator& rectangleToBeSwapped, std::vector<Rectangle>& poolOfRectanglesToSwapWith,
		const std::function<void()>& callback) const {
	for (auto swapRectangle = poolOfRectanglesToSwapWith.begin(); swapRectangle != poolOfRectanglesToSwapWith.end(); swapRectangle++) {
		std::iter_swap(rectangleToBeSwapped, swapRectangle);
		callback();
		std::iter_swap(rectangleToBeSwapped, swapRectangle); //swap back
	}
}

void Enumerator::walkSubset(BStarTree& workingTree, const std::vector<BTreeNode*>::const_iterator& subsetCurrentPosition,
		const std::vector<BTreeNode*>& subset, Enumerator::callbackType callback) const {
	if (subsetCurrentPosition == subset.end()) {
		callback(workingTree);
		return;
	}
	auto currentNode = *subsetCurrentPosition;
	auto rectangles = workingTree.getRectangles();
	forEachSwap(rectangles->begin() + currentNode->getIndex(), *rectangles, [&]() {
		forEachOrientation(*workingTree.getRectangle(currentNode), [&]() {
					walkSubset(workingTree, subsetCurrentPosition + 1, subset, callback);
				});
	});
}

}
}
