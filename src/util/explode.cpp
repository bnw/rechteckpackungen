#include "explode.h"

namespace rechteckpackungen {

std::vector<std::string>* explode(std::string string, char delimiter) {
	std::stringstream stream(string);
	std::string part;
	auto parts = new std::vector<std::string>;
	while (std::getline(stream, part, delimiter)) {
		parts->push_back(part);
	}
	return parts;
}

std::vector<int>* explode2int(std::string string, char delimiter){
	auto parts = explode(string, delimiter);
	auto intParts = new std::vector<int>;
	for(auto part : *parts){
		intParts->push_back(string2int(part));
	}
	delete parts;
	return intParts;
}

}
