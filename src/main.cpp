#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <regex>
#include <algorithm>
#include "action/TestOverlappingAction.h"
#include "action/FindBestByEnumerationAction.h"
#include "action/FindLocalOptimumAction.h"
#include "action/FindGoodPlacementAction.h"
#include "util/string2int.h"

using std::cout;
using std::endl;
using rechteckpackungen::TestOverlappingAction;
using rechteckpackungen::FindBestByEnumerationAction;
using rechteckpackungen::IFileAction;
using rechteckpackungen::FindLocalOptimumAction;
using rechteckpackungen::FindGoodPlacementAction;
using rechteckpackungen::string2int;

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

bool isParameterSet(char const * parameterName, int argc, char const *argv[]){
	for(int i = 1; i < argc; i++){
		if(strcmp(parameterName, argv[i]) == 0) {
			return true;
		}
	}
	return false;
}

unsigned getQuality(int argc, char const *argv[]){
	for(int i = 1; i < argc; i++){
		std::regex qualityRegex("-quality=(.+)");
		auto argument = std::string(argv[i]);
		std::smatch matches;
		if(std::regex_search (argument,matches,qualityRegex)) {
			try{
				return string2int(matches[1]);
			}catch (std::runtime_error &e){
				throw std::runtime_error("Only positive integers for quality are allowed");
			}
		}
	}
	return 2;
}

void checkThatOnlyAllowedArgumentsAreSet(std::vector<std::string> allowedArguments, int argc, char const *argv[]){
	for(int i = 1; i < argc; i++){
		auto argument = std::string(argv[i]);
		std::regex regex("^-([a-zA-Z]+)");
		std::smatch matches;
		if(std::regex_search (argument,matches,regex)) {
			if(std::find(allowedArguments.begin(), allowedArguments.end(), matches[1]) == allowedArguments.end()){
				std::stringstream errorMessage;
				errorMessage << "Unknown parameter " << matches[1];
				throw std::runtime_error(errorMessage.str());
			}
		}
	}
}

void printUsageInfo(){
	cout
	<< "Usage: rechteckpackungen.exe MODE FILES [OPTIONS]" << endl
	<< "Available modes:" << endl
	<< "\t test-overlapping, find-optimal-placement, find-good-placement, improve-placement" << endl << endl

	<< "See below for detailed description:" << endl << endl

	<< "test-overlapping FILE" << endl
	<< "\t Tests if the placement described in FILE has any overlapping." << endl << endl

	<< "find-optimal-placement FILE [-noRotation]" << endl
	<< "\t Prints an optimal placement for the instance described in FILE."<< endl
	<< "\t Works by enumerating all possible placements." << endl
	<< "\t -noRotation: Do not roate rectangles to find a better placement." << endl << endl

	<< "find-good-placement FILE [-quality=QUALITY] [-noRotation] [-noTreeMutation]" << endl
	<< "\t Prints a placement for the instance described in FILE." << endl
	<< "\t Works by guessing a solution and then finding a local optimum based on this solution." << endl
	<< "\t If the bounds are rather small, this might not yield any feasable solution," << endl
	<< "\t regardless of QUALITY." << endl
	<< "\t QUALITY (default=2): Number of rectangles that can be mutated." << endl
	<< "\t\t Higher means better results but slower computation." << endl
	<< "\t -noRotation: Do not roate rectangles to find a better placement." << endl
	<< "\t -noTreeMutation: Do not move rectangles around the tree to find a better placement." << endl<< endl

	<< "improve-placement INSTANCE_FILE PLACEMENT_FILE [-quality=QUALITY] [-noRotation] [-noTreeMutation]" << endl
	<< "\t Prints a placement for the instance described in INSTANCE_FILE by finding a" << endl
	<< "\t local optimum based on the compacted(!) placement described in PLACEMENT_FILE." << endl
	<< "\t QUALITY (default=2): Number of rectangles that can be mutated." << endl
	<< "\t\t Higher means better results but slower computation." << endl
	<< "\t -noRotation: Do not roate rectangles to find a better placement." << endl
	<< "\t -noTreeMutation: Do not move rectangles around the tree to find a better placement." << endl<< endl;
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


	try {
		bool noRotation = isParameterSet("-noRotation", argc, argv);
		bool noTreeMutation = isParameterSet("-noTreeMutation", argc, argv);
		unsigned quality = getQuality(argc, argv);

		auto filename = argv[2];

		std::vector<std::string> allowedArguments;

		if (strcmp("test-overlapping", mode) == 0) {
			checkThatOnlyAllowedArgumentsAreSet(allowedArguments, argc, argv);
			auto action = TestOverlappingAction();
			runIFileAction(action, filename);
		} else if (strcmp("find-optimal-placement", mode) == 0) {
			allowedArguments.push_back("noRotation");
			checkThatOnlyAllowedArgumentsAreSet(allowedArguments, argc, argv);
			auto action = FindBestByEnumerationAction(noRotation);
			runIFileAction(action, filename);
		} else if (strcmp("find-good-placement", mode) == 0) {
			allowedArguments.push_back("quality");
			allowedArguments.push_back("noRotation");
			allowedArguments.push_back("noTreeMutation");
			checkThatOnlyAllowedArgumentsAreSet(allowedArguments, argc, argv);
			auto action = FindGoodPlacementAction(quality, noRotation, noTreeMutation);
			runIFileAction(action, filename);
		} else if (strcmp("improve-placement", mode) == 0) {
			allowedArguments.push_back("quality");
			allowedArguments.push_back("noRotation");
			allowedArguments.push_back("noTreeMutation");
			checkThatOnlyAllowedArgumentsAreSet(allowedArguments, argc, argv);
			if (argc < 4) {
				return missingArgumentError();
			}
			auto action = FindLocalOptimumAction(quality, noRotation, noTreeMutation);
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
