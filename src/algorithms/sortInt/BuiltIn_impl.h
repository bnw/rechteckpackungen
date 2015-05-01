#include "BuiltIn.h"

namespace rechteckpackungen {
namespace sortInt {

template<class T>
BuiltIn<T>::~BuiltIn() {
}

template<class T>
void BuiltIn<T>::sort(std::vector<T>* vector, int (*getInt)(const T)) {
	std::sort(vector->begin(), vector->end(), [&getInt](const T a, const T b) {
		return getInt(a) < getInt(b);
	});
}

}
}
