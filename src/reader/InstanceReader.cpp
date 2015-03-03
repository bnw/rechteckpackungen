#include "InstanceReader.h"

namespace rechteckpackungen {

Instance* InstanceReader::read(std::istream& input) {
	std::string line;
	std::getline(input, line);
	auto instance = new Instance(getAreaFromLine(line));

	return instance;
}

Placement* InstanceReader::getAreaFromLine(std::string line) {
	auto parts = explode2int(line, ' ');

	if (parts->size() != 4) {
		throw std::runtime_error(
				"Expected first line to have exactly 4 numbers");
	}

	int xMin = parts->at(0);
	int xMax = parts->at(1);
	int yMin = parts->at(2);
	int yMax = parts->at(3);

	delete parts;

	return new Placement(xMin, xMax, yMin, yMax);
}

}
