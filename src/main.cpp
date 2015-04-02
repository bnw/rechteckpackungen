#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include "action/OverlappingAction.h"
#include "action/FindBestByEnumeration.h"
#include "action/IFileAction.h"

using std::cout;
using std::endl;
using rechteckpackungen::OverlappingAction;
using rechteckpackungen::FindBestByEnumeration;
using rechteckpackungen::IFileAction;

int runIFileAction(IFileAction& action, char const *filename) {
	std::ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		std::cout << "Cannot read file " << filename << std::endl;
		return 1;
	}
	action.run(file, std::cout);
	file.close();
	return 0;
}

int main(int argc, char const *argv[]) {

	auto usageInfo = "Usage: rechteckpackungen.exe { test-overlapping | find-optimal-placement } file";

	if (argc < 3) {
		cout << usageInfo << endl;
		return 0;
	}

	auto mode = argv[1];
	auto filename = argv[2];

	try {
		if (strcmp("test-overlapping", mode) == 0) {
			auto action = OverlappingAction();
			return runIFileAction(action, filename);
		} else if (strcmp("find-optimal-placement", mode) == 0) {
			auto action = FindBestByEnumeration();
			return runIFileAction(action, filename);
		} else {
			cout << "Unrecognized mode '" << mode << "'." << endl << usageInfo << endl;
			return 1;
		}
	} catch (std::runtime_error &e) {
		cout << "An exception occurred:" << endl << e.what() << endl;
	}
	return 0;
}
