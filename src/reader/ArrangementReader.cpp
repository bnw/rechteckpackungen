#include "ArrangementReader.h"

namespace rechteckpackungen {

Arrangement* ArrangementReader::read(std::istream& input) {
	auto arrangement = new Arrangement;
	std::string line;
	while (std::getline(input, line)) {
		arrangement->add(this->getPositionedRectangleFromLine(line));
	}

	return arrangement;
}

PositionedRectangle* ArrangementReader::getPositionedRectangleFromLine(std::string& line) {
	auto parts = explode2int(line, ' ');
	if (parts->size() != 6) {
		throw std::runtime_error(
				"Expected each line to contain exactly 6 numbers");
	}
	int xMin = parts->at(0);
	int xMax = parts->at(1);
	int yMin = parts->at(2);
	int yMax = parts->at(3);

	delete parts;

	return new PositionedRectangle(xMin, xMax, yMin, yMax);
}

}
