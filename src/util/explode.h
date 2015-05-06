#ifndef SRC_UTIL_EXPLODE_H_
#define SRC_UTIL_EXPLODE_H_

#include <vector>
#include <stdio.h>
#include <string>
#include <sstream>
#include "util/string2int.h"
#include "util/safeGetline.h"

namespace rechteckpackungen {

/**
 * Splits string at each delimiter (dropping the delimiter).
 */
extern std::vector<std::string>* explode(std::string string, char delimiter);

/**
 * Same as explode, but converts the vector of strings to an vector of ints by calling string2int.
 */
extern std::vector<int>* explode2int(std::string string, char delimiter, int expectedSize = 1);

}

#endif
