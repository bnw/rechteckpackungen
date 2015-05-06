#include "string2int.h"

namespace rechteckpackungen {

int string2int(std::string string) {
	for (auto k = string.begin(); k != string.end(); ++k) {
		if (!isdigit(*k)) {
			throw std::runtime_error("Could not convert string to int");
		}
	}
	return atoi(string.c_str());
}

}
