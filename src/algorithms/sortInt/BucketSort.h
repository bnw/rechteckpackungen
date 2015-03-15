#ifndef SRC_ALGORITHMS_SORTINT_BUCKETSORT_H_
#define SRC_ALGORITHMS_SORTINT_BUCKETSORT_H_

#include <algorithm>
#include <vector>
#include "algorithms/sortInt/IIntSorter.h"

namespace rechteckpackungen {
namespace sortInt {

class BucketSort: public virtual IIntSorter {
public:
	virtual ~BucketSort();
	/**
	 * Complexity: O(n * log(n))
	 * Memory: ?
	 */
	virtual void sort(std::vector<void*>*, int (*getInt)(const void *));
};

}
}

#endif
