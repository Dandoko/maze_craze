#ifndef NON_EMPTY_PATH_H
#define NON_EMPTY_PATH_H

#include "path.h"

class NonEmptyPath : public Path {
private:
public:
	NonEmptyPath(char shape, int color);
	NonEmptyPath(const NonEmptyPath&) = delete;
	virtual ~NonEmptyPath();

	bool isNonEmptyPath();

	virtual bool isStartPath();
	virtual bool isEndPath();
};

#endif
