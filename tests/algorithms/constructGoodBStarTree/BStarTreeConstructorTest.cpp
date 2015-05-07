#include "cute.h"
#include "BStarTreeConstructorTest.h"

#include "algorithms/constructGoodBStarTree/BStarTreeConstructor.h"
#include "instance/Instance.h"
#include "reader/InstanceReader.h"
#include <stdio.h>

namespace rechteckpackungen {
namespace constructGoodBStarTree {

void testThatTreeWasCompletelyConstructed() {
	auto constructor = constructGoodBStarTree::BStarTreeConstructor();
	auto instanceReader = InstanceReader();
	std::stringstream input;
	input << "0 5 1 7" << std::endl << "3 2" << std::endl << "2 4" << std::endl << "2 2";
	auto instance = instanceReader.read(input);

	auto tree = constructor.create(*instance);

	for(auto node : tree->getNodes()){
		ASSERT(node->hasParent() || tree->isRoot(node));
	}
}

cute::suite make_suite_BStarTreeConstructorTest() {
	cute::suite s;
	s.push_back(CUTE(testThatTreeWasCompletelyConstructed));
	return s;
}

}
}
