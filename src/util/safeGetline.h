#ifndef SRC_UTIL_SAFEGETLINE_H_
#define SRC_UTIL_SAFEGETLINE_H_

#include <fstream>
#include <string.h>

namespace rechteckpackungen {

extern std::istream& safeGetline(std::istream& is, std::string& str);
extern std::istream& safeGetline(std::istream& is, std::string& str, char delim);

}

#endif /* SRC_UTIL_SAFEGETLINE_H_ */
