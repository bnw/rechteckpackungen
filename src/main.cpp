#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include "action/TestOverlappingAction.h"

using std::cout;
using std::endl;
using rechteckpackungen::TestOverlappingAction;

int main(int argc, char const *argv[]) {

	auto usageInfo = "Usage: rechteckpackungen.exe {test-overlapping} file";

	if (argc < 3) {
		cout << usageInfo << endl;
		return 0;
	}

	auto mode = argv[1];
	auto filename = argv[2];

	if (strcmp("test-overlapping", mode) == 0) {
		auto action = TestOverlappingAction();
		try{
			action.run(filename);
		}catch(std::runtime_error &e){
			cout << "An exception occurred:" << std::endl << e.what();
		}
	} else {
		cout << "Unrecognized mode '" << mode << "'." << endl << usageInfo << endl;
	}

	return 0;
}
