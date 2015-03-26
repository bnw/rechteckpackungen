#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include "action/TestOverlappingAction.h"
#include "action/FindBestByEnumeration.h"

using std::cout;
using std::endl;
using rechteckpackungen::TestOverlappingAction;
using rechteckpackungen::FindBestByEnumeration;

int main(int argc, char const *argv[]) {

	auto usageInfo = "Usage: rechteckpackungen.exe {test-overlapping|find-optimal-placement} file";

	if (argc < 3) {
		cout << usageInfo << endl;
		return 0;
	}

	auto mode = argv[1];
	auto filename = argv[2];

	if (strcmp("test-overlapping", mode) == 0) {
		auto action = TestOverlappingAction();
		try {
			action.run(filename);
		} catch (std::runtime_error &e) {
			cout << "An exception occurred:" << endl << e.what() << endl;
		}
	} else if (strcmp("find-optimal-placement", mode) == 0) {
		try {
			auto action = FindBestByEnumeration();
			std::ifstream file;
			file.open(filename);
			if (!file.is_open()) {
				std::cout << "Cannot read file " << filename << std::endl;
				return 1;
			}
			action.run(file, std::cout);
			file.close();
		} catch (std::runtime_error &e) {
			cout << "An exception occurred:" << endl << e.what() << endl;
		}
	} else {
		cout << "Unrecognized mode '" << mode << "'." << endl << usageInfo << endl;
	}

	return 0;
}
