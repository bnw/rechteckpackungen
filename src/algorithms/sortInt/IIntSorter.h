#ifndef SRC_ALGORITHMS_SORTINT_IINTSORTER_H_
#define SRC_ALGORITHMS_SORTINT_IINTSORTER_H_

#include <vector>

namespace rechteckpackungen {
namespace sortInt {

class IIntSorter {
public:
	virtual ~IIntSorter() {
	}
	virtual void sort(std::vector<void*>*, int(*getInt)(const void *)) = 0;
};

}
}

#endif
