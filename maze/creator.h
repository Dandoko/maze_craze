#ifndef CREATOR_H
#define CREATOR_H

#include "unit.h"

class Creator : public Unit {
private:
public:
	Creator(char shape);
	Creator(const Creator&) = delete;
	virtual ~Creator();

	bool isCreator();
};

#endif