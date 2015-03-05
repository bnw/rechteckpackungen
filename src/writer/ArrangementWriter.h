#ifndef SRC_WRITER_ARRANGEMENTWRITER_H_
#define SRC_WRITER_ARRANGEMENTWRITER_H_

#include "arrangement/Arrangement.h"
#include <string>
#include <sstream>

namespace rechteckpackungen {

class ArrangementWriter {
public:
	std::string toString(Arrangement* arrangement);
};

}
#endif
