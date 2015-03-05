#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "RectangleTest.h"
#include "reader/ArrangementReaderTest.h"
#include "reader/InstanceReaderTest.h"
#include "util/ExplodeTest.h"
#include "arrangement/ArrangementTest.h"
#include "algorithms/testForOverlapping/SweeplineTest.h"
#include "util/String2intTest.h"
#include "writer/ArrangementWriterTest.h"


void runAllTests(int argc, char const *argv[]) {
	cute::suite s;

	s += rechteckpackungen::make_suite_Rectangle();
	s += rechteckpackungen::make_suite_ArrangementReader();
	s += rechteckpackungen::make_suite_InstanceReaderTest();
	s += rechteckpackungen::make_suite_ExplodeTest();
	s += rechteckpackungen::make_suite_ArrangementTest();
	s += rechteckpackungen::make_suite_SweeplineTest();
	s += rechteckpackungen::make_suite_String2intTest();
	s += rechteckpackungen::make_suite_ArrangementWriterTest();

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}
