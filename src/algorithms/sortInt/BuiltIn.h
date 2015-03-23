#ifndef SRC_ALGORITHMS_SORTINT_BUILTIN_H_
#define SRC_ALGORITHMS_SORTINT_BUILTIN_H_

#include "algorithms/sortInt/IIntSorter.h"
#include <vector>
#include <algorithm>

namespace rechteckpackungen {
namespace sortInt {

class BuiltIn: public virtual IIntSorter {
public:
	virtual ~BuiltIn();
	/**
	 * Complexity: O(n * log(n))
	 * Memory: ?
	 */
	virtual void sort(std::vector<void*>*, int(*getInt)(const void *));
private:
};

}
}

#endif /* SRC_ALGORITHMS_SORTINT_BUILTIN_H_ */