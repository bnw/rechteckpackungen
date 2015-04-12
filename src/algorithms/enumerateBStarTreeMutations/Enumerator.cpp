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

void Enumerator::forEachMovement(const BStarTree& tree, const int& indexOfNodeToBeMoved,
		const std::function<void(BStarTree& workingTree)>& callback) const {
	BStarTree preparedTree = BStarTree(tree);
	preparedTree.remove(preparedTree.at(indexOfNodeToBeMoved));

	for (int targetNodeId = 0; targetNodeId < tree.getSize(); targetNodeId++) {
		if(targetNodeId == indexOfNodeToBeMoved){
			continue;
		}
		BStarTree workingTree1 = BStarTree(preparedTree);
		workingTree1.squeezeInLeftChild(workingTree1.at(targetNodeId), workingTree1.at(indexOfNodeToBeMoved));
		callback(workingTree1);

		BStarTree workingTree2 = BStarTree(preparedTree);
		workingTree2.squeezeInRightChild(workingTree2.at(targetNodeId), workingTree2.at(indexOfNodeToBeMoved));
		callback(workingTree2);
	}
}

void Enumerator::walkSubset(BStarTree& workingTree, const std::vector<BTreeNode*>::const_iterator& subsetCurrentPosition,
		const std::vector<BTreeNode*>& subset, Enumerator::callbackType callback) const {
	if (subsetCurrentPosition == subset.end()) {
		callback(workingTree);
		return;
	}
	BTreeNode* currentNode = *subsetCurrentPosition;
	auto rectangles = workingTree.getRectangles();
	forEachMovement(workingTree, currentNode->getIndex(),
			[&currentNode, &rectangles, &subset, &subsetCurrentPosition, &callback, this](BStarTree& workingTree) {
				forEachSwap(rectangles->begin() + currentNode->getIndex(), *rectangles, [&]() {
							forEachOrientation(*workingTree.getRectangle(currentNode), [&]() {
										walkSubset(workingTree, subsetCurrentPosition + 1, subset, callback);
									});
						});
			});

}

}
}
