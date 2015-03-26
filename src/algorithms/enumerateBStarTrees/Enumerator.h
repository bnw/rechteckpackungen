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
	void forEachBStarTree(std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>> rectangles, const std::function<void(BStarTree*)>& callback);
protected:
	void walkTree(BStarTree* tree, int rootIndex, int currentIndex, const std::function<void(BStarTree*)>& callback);
};

}
}

#endif /* SRC_ALGORITHMS_ENUMERATEBSTARTREES_ENUMERATOR_H_ */
