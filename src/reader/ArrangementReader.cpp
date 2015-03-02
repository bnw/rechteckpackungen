#include "ArrangementReader.h"

namespace rechteckpackungen {

Arrangement* ArrangementReader::read(std::istream& input) {
	auto arrangement = new Arrangement;
	std::string line;
	while (std::getline(input, line)) {
		auto placement = this->getPlacementFromLine(line);
		arrangement->add(placement);
	}

	return arrangement;
}

Placement* ArrangementReader::getPlacementFromLine(std::string& line) {
	auto parts = explode(line, ' ');
	if (parts->size() != 6) {
		throw std::runtime_error(
				"Expected each line to contain exactly 6 numbers");
	}
	int xMin = atoi(parts->at(0).c_str());
	int xMax = atoi(parts->at(1).c_str());
	int yMin = atoi(parts->at(2).c_str());
	int yMax = atoi(parts->at(3).c_str());

	auto rect = new Rectangle(xMax - xMin, yMax - yMin);
	auto coords = new Coordinates(xMin, yMin);

	delete parts;

	return new Placement(rect, coords);
}

}
