#include "BucketSort.h"

namespace rechteckpackungen {
namespace sortInt {

BucketSort::BucketSort(bool reverse) :
		reverse(reverse) {
}

BucketSort::~BucketSort() {
}

void BucketSort::sort(std::vector<void*>* vector, int (*getInt)(const void *)) {
	auto max_element = std::max_element(vector->begin(), vector->end(), [getInt, this](const void* a, const void* b) {return getInt(a) < getInt(b);});
	int max = getInt(*max_element);
	auto buckets = std::vector<std::vector<void*>>(max + 1);
	for (auto element : *vector) {
		buckets.at(getInt(element)).push_back(element);
	}

	if (reverse) {
		int i = vector->size() - 1;
		for (auto bucket : buckets) {
			for (auto element : bucket) {
				vector->at(i--) = element;
			}
		}
	} else {
		int i = 0;
		for (auto bucket : buckets) {
			for (auto element : bucket) {
				vector->at(i++) = element;
			}
		}
	}
}

}
}