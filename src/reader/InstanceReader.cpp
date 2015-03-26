#include "InstanceReader.h"

namespace rechteckpackungen {

Instance* InstanceReader::read(std::istream& input) {
	std::string line;
	safeGetline(input, line);
	auto instance = new Instance(getAreaFromLine(line));

	while (safeGetline(input, line)) {
		auto parts = explode(line, ' ');
		if(parts->size() == 0){
			//ignore empty lines
			delete parts;
			continue;
		}
		if (parts->at(0) == "B" || parts->at(0) == "Net") {
			//Dont read blockades or nets
			delete parts;
			break;
		}
		instance->addRectangle(getRectangleFromLineParts(parts));
		delete parts;
	}

	return instance;
}

std::shared_ptr<Rectangle> InstanceReader::getRectangleFromLineParts(
		std::vector<std::string>* parts) {
	if (parts->size() != 2) {
		throw std::runtime_error(
				"Expected rectangle lines to contain exactly 2 numbers");
	}
	return std::shared_ptr<Rectangle>(new Rectangle(string2int(parts->at(0)), string2int(parts->at(1))));
}

std::shared_ptr<PositionedRectangle> InstanceReader::getAreaFromLine(std::string line) {
	auto parts = explode2int(line, ' ');

	if (parts->size() != 4) {
		throw std::runtime_error(
				"Expected first line to contain exactly 4 numbers");
	}

	int xMin = parts->at(0);
	int xMax = parts->at(1);
	int yMin = parts->at(2);
	int yMax = parts->at(3);

	delete parts;

	return std::shared_ptr<PositionedRectangle>(new PositionedRectangle(xMin, xMax, yMin, yMax));
}

}
