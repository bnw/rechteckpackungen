#ifndef SRC_READER_ARRANGEMENTREADER_H_
#define SRC_READER_ARRANGEMENTREADER_H_

#include "util/explode.h"
#include "arrangement/Arrangement.h"
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdexcept>
#include <cstdlib>

namespace rechteckpackungen {

class ArrangementReader {
public:
	Arrangement* read(std::istream& filename);
private:
	Placement* getPlacementFromLine(std::string& line);
};

}

#endif
