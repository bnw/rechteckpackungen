#ifndef SRC_UTIL_EXPLODE_H_
#define SRC_UTIL_EXPLODE_H_

#include <vector>
#include <stdio.h>
#include <string>
#include <sstream>
#include "util/string2int.h"
#include "util/saveGetline.h"

namespace rechteckpackungen {

extern std::vector<std::string>* explode(std::string string, char delimiter);
extern std::vector<int>* explode2int(std::string string, char delimiter);

}

#endif
