#ifndef PATH_H
#define PATH_H

#include "cell.h"

class Path : public Cell {
private:
public:
	Path(char shape);
	Path(const Path&) = delete;
	virtual ~Path();

	bool isPath();

	virtual bool isEmptyPath();
	virtual bool isNonEmptyPath();
};

#endif