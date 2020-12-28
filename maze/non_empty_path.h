#ifndef NON_EMPTY_PATH_H
#define NON_EMPTY_PATH_H

#include "path.h"

class NonEmptyPath : public Path {
private:
	int m_Color;
public:
	NonEmptyPath(char shape, int color);
	NonEmptyPath(const NonEmptyPath&) = delete;
	virtual ~NonEmptyPath();

	bool isNonEmptyPath();

	virtual bool isStartPath();
	virtual bool isEndPath();
};

#endif
