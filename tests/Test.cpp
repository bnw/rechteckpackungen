#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "RectangleTest.h"
#include "reader/PlacementReaderTest.h"
#include "reader/InstanceReaderTest.h"
#include "util/ExplodeTest.h"
#include "arrangement/PlacementTest.h"
#include "arrangement/PositionedRectangleTest.h"
#include "algorithms/testForOverlapping/SweeplineTest.h"
#include "algorithms/sortInt/IntSorterTest.h"
#include "algorithms/placement2BStarTree/BStarTreeFactoryTest.h"
#include "algorithms/bStartTree2Placement/PlacementFactoryTest.h"
#include "algorithms/enumerateBStarTrees/EnumeratorTest.h"
#include "util/String2intTest.h"
#include "writer/PlacementWriterTest.h"
#include "BTree/BTreeNodeTest.h"


void runAllTests(int argc, char const *argv[]) {
	cute::suite s;

	s += rechteckpackungen::make_suite_Rectangle();
	s += rechteckpackungen::make_suite_PlacementReader();
	s += rechteckpackungen::make_suite_InstanceReaderTest();
	s += rechteckpackungen::make_suite_ExplodeTest();
	s += rechteckpackungen::make_suite_PlacementTest();
	s += rechteckpackungen::make_suite_PositionedRectangleTest();
	s += rechteckpackungen::make_suite_SweeplineTest();
	s += rechteckpackungen::make_suite_String2intTest();
	s += rechteckpackungen::make_suite_PlacementWriterTest();
	s += rechteckpackungen::make_suite_BStarTreeFactory();
	s += rechteckpackungen::make_suite_SortIntTest();
	s += rechteckpackungen::make_suite_PlacementFactoryTest();
	s += rechteckpackungen::make_suite_BTreeNodeTest();
	s += rechteckpackungen::make_suite_EnumeratorTest();

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}
