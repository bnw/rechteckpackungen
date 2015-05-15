#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include "action/TestOverlappingAction.h"
#include "action/FindBestByEnumeration.h"
#include "action/FindLocalOptimum.h"
#include "action/FindGoodPlacement.h"

using std::cout;
using std::endl;
using rechteckpackungen::TestOverlappingAction;
using rechteckpackungen::FindBestByEnumeration;
using rechteckpackungen::IFileAction;
using rechteckpackungen::FindLocalOptimum;
using rechteckpackungen::FindGoodPlacement;

std::ifstream* openFile(char const *filename) {
	auto file = new std::ifstream;
	try {
		file->open(filename);
	} catch (std::ios_base::failure &e) {
	}
	if (!file->is_open() || !file->good()) {
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

void printUsageInfo(){
	cout
	<< "Usage: rechteckpackungen.exe MODE FILES [OPTIONS]" << endl
	<< "Available modes:" << endl
	<< "\t test-overlapping, find-optimal-placement, find-good-placement, improve-placement" << endl << endl

	<< "See below for detailed description:" << endl << endl

	<< "test-overlapping FILE" << endl
	<< "\t Tests if the placement described in FILE has any overlapping." << endl << endl

	<< "find-optimal-placement FILE" << endl
	<< "\t Prints an optimal placement for the instance described in FILE."<< endl
	<< "\t Works by enumerating all possible placements." << endl << endl

	<< "find-good-placement FILE" << endl
	<< "\t Prints a placement for the instance described in FILE. Works by guessing a" << endl
	<< "\t solution and then finding a local optimum based on this solution." << endl << endl

	<< "improve-placement INSTANCE_FILE PLACEMENT_FILE" << endl
	<< "\t Prints a placement for the instance described in INSTANCE_FILE by finding a" << endl
	<< "\t local optimum based on the placement described in PLACEMENT_FILE." << endl;
}

void printUsageHint(){
	cout << "Try 'rechteckpackungen.exe help' for more information." << endl;
}

int missingArgumentError(){
	cout << "Missing argument(s)!" << endl << endl;
	printUsageHint();
	return 1;
}

int main(int argc, char const *argv[]) {
	if (argc < 2) {
		return missingArgumentError();
	}
	auto mode = argv[1];

	if(strcmp("help", mode) == 0){
		printUsageInfo();
		return 0;
	}

	if (argc < 3) {
		return missingArgumentError();
	}

	auto filename = argv[2];

	try {
		if (strcmp("test-overlapping", mode) == 0) {
			auto action = TestOverlappingAction();
			runIFileAction(action, filename);
		} else if (strcmp("find-optimal-placement", mode) == 0) {
			auto action = FindBestByEnumeration();
			runIFileAction(action, filename);
		} else if (strcmp("find-good-placement", mode) == 0) {
			auto action = FindGoodPlacement();
			runIFileAction(action, filename);
		} else if (strcmp("improve-placement", mode) == 0) {
			if (argc < 4) {
				return missingArgumentError();
			}
			auto action = FindLocalOptimum(1);
			auto instanceFile = openFile(filename);
			auto initialPlacementFile = openFile(argv[3]);
			action.run(*instanceFile, *initialPlacementFile, std::cout);
			delete instanceFile;
			delete initialPlacementFile;
		} else {
			cout << "Unrecognized mode '" << mode << "'." << endl;
			printUsageHint();
			return 1;
		}
	} catch (std::runtime_error &e) {
		cout << "An exception occurred:" << endl << e.what() << endl;
		return 1;
	}
	return 0;
}
