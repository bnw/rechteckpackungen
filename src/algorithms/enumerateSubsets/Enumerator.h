#ifndef SRC_ALGORITHMS_ENUMERATESUBSETS_ENUMERATOR_H_
#define SRC_ALGORITHMS_ENUMERATESUBSETS_ENUMERATOR_H_

#include <vector>
#include <functional>

namespace rechteckpackungen {
namespace enumerateSubsets {

class Enumerator {
public:
	typedef const std::function<void(const std::vector<void*>&)>& callbackType;
	void forEachSubset(const std::vector<void*>& set, unsigned sizeOfSubset, callbackType callback) const;
};

}
}

#endif /* SRC_ALGORITHMS_ENUMERATESUBSETS_ENUMERATOR_H_ */
