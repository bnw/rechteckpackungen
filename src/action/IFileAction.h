#ifndef SRC_ACTION_IFILEACTION_H_
#define SRC_ACTION_IFILEACTION_H_

namespace rechteckpackungen {

class IFileAction {
public:
	virtual ~IFileAction() {
	}
	virtual void run(std::istream& instance, std::ostream& output) = 0;
};

}

#endif /* SRC_ACTION_IFILEACTION_H_ */
