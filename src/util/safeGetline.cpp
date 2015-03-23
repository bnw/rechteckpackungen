#include "safeGetline.h"

namespace rechteckpackungen {

std::istream& safeGetline(std::istream& is, std::string& line) {
	return safeGetline(is, line, '\n');
}

std::istream& safeGetline(std::istream& is, std::string& line, char delimiter) {
	std::getline(is, line, delimiter);
	if (!line.empty() && (*(line.rbegin()) == '\r')) {
		line.erase(line.length() - 1, 1);
	}
	return is;
}

}
