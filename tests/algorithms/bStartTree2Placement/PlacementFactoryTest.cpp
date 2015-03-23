#include "cute.h"
#include "PlacementFactoryTest.h"

namespace rechteckpackungen {


void thisIsAPlacementFactoryTestTest() {
	//TODO
}

cute::suite make_suite_PlacementFactoryTest() {
	cute::suite s;
	s.push_back(CUTE(thisIsAPlacementFactoryTestTest));
	return s;
}

}
