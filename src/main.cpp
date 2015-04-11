#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include "action/OverlappingAction.h"
#include "action/FindBestByEnumeration.h"
#include "action/IFileAction.h"
#include "action/FindLocalOptimum.h"

using std::cout;
using std::endl;
using rechteckpackungen::OverlappingAction;
using rechteckpackungen::FindBestByEnumeration;
using rechteckpackungen::IFileAction;
using rechteckpackungen::FindLocalOptimum;

std::ifstream* openFile(char const *filename) {
	auto file = new std::ifstream;
	try {
		file->open(filename);
	} catch (std::ios_base::failure &e) {
	}
	if (!file->is_open() || !file->good()){
		std::stringstream errorMessage;
		errorMessage << "Cannot open file " << filename;
		throw std::runtime_error(errorMessage.str());
	}
	return file;
}

void runIFileAction(IFileAction& action, char const *filename) {
	auto file = openFile(filename);
	action.run(*file, std::cout);
	file->close();
	delete file;
}

int main(int argc, char const *argv[]) {

	auto usageInfo =
			"Usage: rechteckpackungen.exe { test-overlapping | find-optimal-placement | find-local-optimal-placement } file [initial_placement_file]";

	if (argc < 3) {
		cout << usageInfo << endl;
		return 1;
	}

	auto mode = argv[1];
	auto filename = argv[2];

	try {
		if (strcmp("test-overlapping", mode) == 0) {
			auto action = OverlappingAction();
			runIFileAction(action, filename);
		} else if (strcmp("find-optimal-placement", mode) == 0) {
			auto action = FindBestByEnumeration();
			runIFileAction(action, filename);
		} else if (strcmp("find-local-optimal-placement", mode) == 0) {
			if (argc < 4) {
				cout << "Usage: rechteckpackungen.exe find-local-optimal-placement instance_file initial_placement_file" << endl;
				return 1;
			}
			auto action = FindLocalOptimum(4);
			auto instanceFile = openFile(filename);
			auto initialPlacementFile = openFile(argv[3]);
			action.run(*instanceFile, *initialPlacementFile, std::cout);
			delete instanceFile;
			delete initialPlacementFile;
		} else {
			cout << "Unrecognized mode '" << mode << "'." << endl << usageInfo << endl;
			return 1;
		}
	} catch (std::runtime_error &e) {
		cout << "An exception occurred:" << endl << e.what() << endl;
		return 1;
	}
	return 0;
}
