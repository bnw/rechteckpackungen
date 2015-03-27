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
	 * Calls callback once for every possible BStarTree.
	 * If callback returns false, enumeration stops.
	 */
	void forEachBStarTree(std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>> rectangles, const std::function<bool(BStarTree*)>& callback);
protected:
	/**
	 * If returns false, enumeration should stop
	 */
	bool walkTree(BStarTree* tree, int rootIndex, int currentIndex, const std::function<bool(BStarTree*)>& callback);
};

}
}

#endif /* SRC_ALGORITHMS_ENUMERATEBSTARTREES_ENUMERATOR_H_ */
