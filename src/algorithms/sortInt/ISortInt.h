#ifndef SRC_ALGORITHMS_SORTINT_ISORTINT_H_
#define SRC_ALGORITHMS_SORTINT_ISORTINT_H_

#include <vector>

namespace rechteckpackungen {
namespace sortInt {

class ISortInt {
public:
	virtual ~ISortInt() {
	}
	virtual void sort(std::vector<void*>*, int(*getInt)(const void *)) = 0;
};

}
}

#endif
