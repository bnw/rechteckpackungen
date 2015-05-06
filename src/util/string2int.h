#ifndef SRC_UTIL_STRING2INT_H_
#define SRC_UTIL_STRING2INT_H_

#include <string>
#include <stdexcept>
#include <cstdlib>

namespace rechteckpackungen {

/**
 * Converts a number string to an int.
 * @Throws std::runtime_error
 */
extern int string2int(std::string string);

}

#endif /* SRC_UTIL_STRING2INT_H_ */
