#ifndef SRC_ALGORITHMS_ENUMERATESUBSETS_ENUMERATOR_H_
#define SRC_ALGORITHMS_ENUMERATESUBSETS_ENUMERATOR_H_

#include <vector>
#include <functional>

namespace rechteckpackungen {
namespace enumerateSubsets {

class Enumerator {
public:
	void forEachSubset(const std::vector<void*>& set, const unsigned& sizeOfSubset, const std::function<void(const std::vector<void*>*)>& callback) const;
protected:
	void constructSubset(const std::vector<void*>& set, unsigned setIndex, unsigned subsetIndex, std::vector<void*>& partialSubset,
			const std::function<void(const std::vector<void*>*)>& callback) const;
};

}
}

#endif /* SRC_ALGORITHMS_ENUMERATESUBSETS_ENUMERATOR_H_ */
