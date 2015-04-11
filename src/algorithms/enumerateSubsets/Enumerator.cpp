#include "Enumerator.h"

namespace rechteckpackungen {

namespace enumerateSubsets {

void Enumerator::forEachSubset(const std::vector<void*>& set, const unsigned& sizeOfSubset, const std::function<void(const std::vector<void*>*)>& callback) const {
	auto partialSubset = std::vector<void*>(sizeOfSubset, nullptr);
	constructSubset(set, 0, 0, partialSubset, callback);
}

void Enumerator::constructSubset(const std::vector<void*>& set, unsigned setIndex, unsigned subsetIndex, std::vector<void*>& partialSubset,
		const std::function<void(const std::vector<void*>*)>& callback) const{
	auto sizeOfSubset = partialSubset.size();
	if (subsetIndex == sizeOfSubset) {
		callback(&partialSubset);
		return;
	}
	for (auto i = setIndex; i <= set.size() - (sizeOfSubset - subsetIndex); i++) {
		partialSubset.at(subsetIndex) = set.at(i);
		constructSubset(set, i + 1, subsetIndex + 1, partialSubset, callback);
	}
}

}
}
