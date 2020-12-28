#ifndef START_PATH_H
#define START_PATH_H

#include "non_empty_path.h"

class StartPath : public NonEmptyPath {
private:
public:
	StartPath(char shape);
	StartPath(const StartPath&) = delete;
	virtual ~StartPath();

	bool isStartPath();
};

#endif
