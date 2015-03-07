#ifndef SRC_UTIL_SAVEGETLINE_H_
#define SRC_UTIL_SAVEGETLINE_H_

#include <fstream>
#include <string.h>

namespace rechteckpackungen {

extern std::istream& saveGetline(std::istream& is, std::string& str);
extern std::istream& saveGetline(std::istream& is, std::string& str, char delim);

}

#endif /* SRC_UTIL_SAVEGETLINE_H_ */
