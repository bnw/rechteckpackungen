#include "string2int.h"

namespace rechteckpackungen {

int string2int(std::string string) {
	if(string.length() == 0){
		throw std::runtime_error("Could not convert empty string to int");
	}
	for (auto k = string.begin(); k != string.end(); ++k) {
		if (!isdigit(*k)) {
			throw std::runtime_error("Could not convert string to int");
		}
	}
	return atoi(string.c_str());
}

}
