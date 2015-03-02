#include <string>
#include <cstring>
#include <iostream>
#include "action/TestOverlappingAction.h"

using std::cout;
using std::endl;
using rechteckpackungen::TestOverlappingAction;

int main(int argc, char const *argv[]) {

	auto usageInfo = "Usage: rechteckpackungen.exe {test-overlapping} file";

	if (argc < 3) {
		cout << usageInfo;
		return 0;
	}

	auto mode = argv[1];
	auto filename = argv[2];

	if (strcmp("test-overlapping", mode) == 0) {
		auto action = TestOverlappingAction();
		action.run(filename);
	} else {
		cout << "Unrecognized mode '" << mode << "'." << endl << usageInfo;
	}

	return 0;
}
