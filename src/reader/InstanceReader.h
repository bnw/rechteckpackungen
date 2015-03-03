#ifndef SRC_READER_INSTANCEREADER_H_
#define SRC_READER_INSTANCEREADER_H_

#include "instance/Instance.h"
#include "arrangement/Placement.h"
#include "util/explode.h"
#include "util/string2int.h"
#include <fstream>
#include <stdexcept>
#include <string>

namespace rechteckpackungen {

class InstanceReader {
public:
	Instance* read(std::istream& input);
private:
	Placement* getAreaFromLine(std::string line);
};

}

#endif /* SRC_READER_INSTANCEREADER_H_ */
