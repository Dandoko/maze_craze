#ifndef END_PATH_H
#define END_PATH_H

#include "non_empty_path.h"

class EndPath : public NonEmptyPath {
private:
public:
	EndPath(char shape);
	EndPath(const EndPath&) = delete;
	virtual ~EndPath();

	bool isEndPath();
};

#endif
