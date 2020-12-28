#ifndef EMPTY_PATH_H
#define EMPTY_PATH_H

#include "path.h"

class EmptyPath : public Path {
private:
public:
	EmptyPath();
	EmptyPath(const EmptyPath&) = delete;
	virtual ~EmptyPath();

	bool isEmptyPath();
};

#endif