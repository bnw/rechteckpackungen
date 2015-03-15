#include "cute.h"
#include "IntSorterTest.h"

#include <vector>
#include "algorithms/sortInt/IIntSorter.h"
#include "algorithms/sortInt/BuiltIn.h"
#include "algorithms/sortInt/BucketSort.h"

namespace rechteckpackungen {

void testISortInt(sortInt::IIntSorter &sorter) {
	int a = 1, b = 3, c = 0, d = 1;
	std::vector<int*> vector = { &a, &b, &c, &d };
	sorter.sort((std::vector<void*>*) &vector, [](const void* a) {return *(int*) a;});
	ASSERT(*vector[0] == 0);
	ASSERT(*vector[1] == 1);
	ASSERT(*vector[2] == 1);
	ASSERT(*vector[3] == 3);
}

void testIntSorterBuiltIn(){
	auto sorter = sortInt::BuiltIn();
	testISortInt(sorter);
}

void testIntSorterBucketSort(){
	auto sorter = sortInt::BucketSort();
	testISortInt(sorter);
}

cute::suite make_suite_SortIntTest() {
	cute::suite s;
	s.push_back(CUTE(testIntSorterBuiltIn));
	s.push_back(CUTE(testIntSorterBucketSort));
	return s;
}

}

