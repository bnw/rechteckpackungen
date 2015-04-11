#include "Enumerator.h"

namespace rechteckpackungen {

namespace enumerateSubsets {

template<class T>
void Enumerator<T>::forEachSubset(const vector& set, const unsigned sizeOfSubset, callbackType& callback) const {
	auto partialSubset = vector(sizeOfSubset, nullptr);
	constructSubset(set, 0, 0, partialSubset, callback);
}

template<class T>
void Enumerator<T>::constructSubset(const vector& set, unsigned setIndex, unsigned subsetIndex, vector& partialSubset, callbackType& callback) const {
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

}
}
