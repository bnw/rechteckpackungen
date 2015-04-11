#ifndef SRC_ALGORITHMS_ENUMERATESUBSETS_ENUMERATOR_H_
#define SRC_ALGORITHMS_ENUMERATESUBSETS_ENUMERATOR_H_

#include <vector>
#include <functional>

namespace rechteckpackungen {
namespace enumerateSubsets {

template<class F>
class Enumerator {
public:
	typedef std::vector<F> vector;
	typedef const std::function<void(const vector)> callbackType;
	void forEachSubset(const vector& set, const unsigned sizeOfSubset, callbackType &callback) const;
protected:
	void constructSubset(const vector& set, unsigned setIndex, unsigned subsetIndex, vector& partialSubset, callbackType& callback) const;
};

}
}

#include "Enumerator_impl.h"

#endif /* SRC_ALGORITHMS_ENUMERATESUBSETS_ENUMERATOR_H_ */
