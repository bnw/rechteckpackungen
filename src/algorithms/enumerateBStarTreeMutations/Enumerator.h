#ifndef SRC_ALGORITHMS_ENUMERATEBSTARTREEMUTATIONS_ENUMERATOR_H_
#define SRC_ALGORITHMS_ENUMERATEBSTARTREEMUTATIONS_ENUMERATOR_H_

#include "BTree/BStarTree.h"
#include <vector>
#include <functional>

namespace rechteckpackungen {
namespace enumerateBStarTreeMutations {

class Enumerator {
public:
	typedef const std::function<void(const BStarTree &)> &callbackType;

	/**
	 * If noRotation == true, we will not rotate the rectangles (see forEachOrientation).
	 * If noTreeMutation == true, we will not move rectangles around the tree (see forEachMovement).
	 */
	Enumerator(bool noRotation = false, bool noTreeMutation = false) :
			noTreeMutation(noTreeMutation),
			noRotation(noRotation) { }

	/**
	 * Calls callback for any combination of mutations on the nodes subset.
	 * Mutations are:
	 * 	- Rotation of the rectangle
	 * 	- Swapping the rectangle of a node from subset with that of any other node in the tree
	 * 	- Moving a node from subset to any other position in the tree
	 * @param subset A subset of the BTreeNodes of tree
	 */
	void forEachMutation(const BStarTree &tree, const std::vector<BTreeNode *> &subset, callbackType callback) const;

protected:
	bool noTreeMutation = false;

	bool noRotation = false;

	void forEachOrientation(Rectangle &rectangle, const std::function<void()> &callback) const;

	void forEachSwap(const std::vector<Rectangle>::iterator &rectangleToBeSwapped,
			std::vector<Rectangle> &poolOfRectanglesToSwapWith,
			const std::function<void()> &callback) const;

	void forEachMovement(const BStarTree &tree, const unsigned &indexOfNodeToBeMoved,
			const std::function<void(BStarTree &workingTree)> &callback) const;

	void walkSubset(BStarTree &workingTree, const std::vector<BTreeNode *>::const_iterator &subsetCurrentPosition,
			const std::vector<BTreeNode *> &subset, Enumerator::callbackType callback) const;
};

}
}

#endif /* SRC_ALGORITHMS_ENUMERATEBSTARTREEMUTATIONS_ENUMERATOR_H_ */
