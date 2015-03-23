#ifndef SRC_READER_INSTANCEREADER_H_
#define SRC_READER_INSTANCEREADER_H_

#include "instance/Instance.h"
#include "arrangement/PositionedRectangle.h"
#include "util/explode.h"
#include "util/string2int.h"
#include "util/safeGetline.h"
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace rechteckpackungen {

class InstanceReader {
public:
	Instance* read(std::istream& input);
private:
	PositionedRectangle* getAreaFromLine(std::string line);
	Rectangle* getRectangleFromLineParts(std::vector<std::string>* parts);
};

}

#endif /* SRC_READER_INSTANCEREADER_H_ */
