#include "BuiltIn.h"

namespace rechteckpackungen {
namespace sortInt {

BuiltIn::~BuiltIn(){}

void BuiltIn::sort(std::vector<void*>* vector, int(*getInt)(const void *)) {
	std::sort(vector->begin(), vector->end(), [&getInt](const void* a, const void* b){
		return getInt(a) < getInt(b);
	});
}

}
}
