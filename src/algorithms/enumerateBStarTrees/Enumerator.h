#ifndef SRC_ALGORITHMS_ENUMERATEBSTARTREES_ENUMERATOR_H_
#define SRC_ALGORITHMS_ENUMERATEBSTARTREES_ENUMERATOR_H_

#include "BTree/BStarTree.h"
#include <vector>
#include <functional>
#include <memory>

namespace rechteckpackungen {
namespace enumerateBStarTrees {

class Enumerator {
public:
	/**
	 * If noRotation == true, we will not rotate the rectangles (see forBothRotations).
	 */
	Enumerator(bool noRotation = false) : noRotation(noRotation) { }

	/**
	 * Calls callback once for every possible BStarTree and every rotation of the rectangles.
	 * If callback returns false, enumeration stops.
	 */
	void forEachBStarTree(std::shared_ptr<std::vector<Rectangle>> rectangles,
			const std::function<bool(BStarTree *)> &callback);

protected:
	/**
	 * If returns false, enumeration should stop
	 */
	bool walkTree(BStarTree *tree, int rootIndex, int currentIndex, const std::function<bool(BStarTree *)> &callback);

	bool forBothRotations(const std::function<bool()> &fn, Rectangle *rect);

	bool noRotation;
};

}
}

#endif /* SRC_ALGORITHMS_ENUMERATEBSTARTREES_ENUMERATOR_H_ */
