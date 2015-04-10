#include "Enumerator.h"

namespace rechteckpackungen {
namespace enumerateSubsets {

void constructSubset(const std::vector<void*>& set, unsigned setIndex, unsigned subsetIndex, std::vector<void*>& partialSubset,
		Enumerator::callbackType callback) {
	auto sizeOfSubset = partialSubset.size();
	if (subsetIndex == sizeOfSubset) {
		callback(partialSubset);
		return;
	}
	for (auto i = setIndex; i <= set.size() - (sizeOfSubset - subsetIndex); i++) {
		partialSubset.at(subsetIndex) = set.at(i);
		constructSubset(set, i + 1, subsetIndex + 1, partialSubset, callback);
	}
}

void Enumerator::forEachSubset(const std::vector<void*>& set, unsigned sizeOfSubset, Enumerator::callbackType callback) const {
	auto partialSubset = std::vector<void*>(sizeOfSubset, nullptr);
	constructSubset(set, 0, 0, partialSubset, callback);
}

}
}
