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
	ASSERT(*vector.at(0) == 0);
	ASSERT(*vector.at(1) == 1);
	ASSERT(*vector.at(2) == 1);
	ASSERT(*vector.at(3) == 3);
}

void testISortIntReverse(sortInt::IIntSorter &sorter) {
	int a = 1, b = 3, c = 0, d = 1;
	std::vector<int*> vector = { &a, &b, &c, &d };
	sorter.sort((std::vector<void*>*) &vector, [](const void* a) {return *(int*) a;});
	ASSERT(*vector.at(0) == 3);
	ASSERT(*vector.at(1) == 1);
	ASSERT(*vector.at(2) == 1);
	ASSERT(*vector.at(3) == 0);
}

void testIntSorterBuiltIn(){
	auto sorter = sortInt::BuiltIn();
	testISortInt(sorter);
}

void testIntSorterBucketSort(){
	auto sorter = sortInt::BucketSort(false);
	testISortInt(sorter);
	auto sorterReverse = sortInt::BucketSort(true);
	testISortIntReverse(sorterReverse);
}

cute::suite make_suite_SortIntTest() {
	cute::suite s;
	s.push_back(CUTE(testIntSorterBuiltIn));
	s.push_back(CUTE(testIntSorterBucketSort));
	return s;
}

}

