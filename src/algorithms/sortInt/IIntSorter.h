#ifndef SRC_ALGORITHMS_SORTINT_IINTSORTER_H_
#define SRC_ALGORITHMS_SORTINT_IINTSORTER_H_

#include <vector>

namespace rechteckpackungen {
namespace sortInt {

template<class T>
class IIntSorter {
public:
	virtual ~IIntSorter() {
	}
	virtual void sort(std::vector<T>*, int(*getInt)(const T)) = 0;
};

}
}

#endif
