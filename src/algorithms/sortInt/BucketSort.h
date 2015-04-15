#ifndef SRC_ALGORITHMS_SORTINT_BUCKETSORT_H_
#define SRC_ALGORITHMS_SORTINT_BUCKETSORT_H_

#include <algorithm>
#include <vector>
#include "algorithms/sortInt/IIntSorter.h"

namespace rechteckpackungen {
namespace sortInt {

template<class T>
class BucketSort: public virtual IIntSorter<T> {
public:
	BucketSort(bool reverse);
	virtual ~BucketSort();
	/**
	 * Complexity: O(n)
	 * Memory: O(n)
	 */
	virtual void sort(std::vector<T>*, int (*getInt)(const T));
private:
	bool reverse = false;
};

}
}

#include "BucketSort_impl.h"

#endif
