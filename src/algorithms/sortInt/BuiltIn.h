#ifndef SRC_ALGORITHMS_SORTINT_BUILTIN_H_
#define SRC_ALGORITHMS_SORTINT_BUILTIN_H_

#include "algorithms/sortInt/IIntSorter.h"
#include <vector>
#include <algorithm>

namespace rechteckpackungen {
namespace sortInt {

template<class T>
class BuiltIn: public virtual IIntSorter<T> {
public:
	virtual ~BuiltIn();
	/**
	 * Complexity: O(n * log(n))
	 * Memory: ?
	 */
	virtual void sort(std::vector<T>*, int(*getInt)(const T));
private:
};

}
}

#include "BuiltIn_impl.h"

#endif /* SRC_ALGORITHMS_SORTINT_BUILTIN_H_ */
