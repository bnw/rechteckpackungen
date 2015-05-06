#ifndef SRC_UTIL_SAFEGETLINE_H_
#define SRC_UTIL_SAFEGETLINE_H_

#include <fstream>
#include <string.h>

namespace rechteckpackungen {

/**
 * Same as std::getline, but works with \n and \n\r as newline-delimiters (behavior of std::getline
 * is OS dependent).
 */
extern std::istream& safeGetline(std::istream& is, std::string& str);
extern std::istream& safeGetline(std::istream& is, std::string& str, char delim);

}

#endif /* SRC_UTIL_SAFEGETLINE_H_ */
