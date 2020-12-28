#ifndef SOLVER_H
#define SOLVER_H

#include "unit.h"

class Solver : public Unit {
private:
public:
	Solver(char shape);
	Solver(const Solver&) = delete;
	virtual ~Solver();

	bool isSolver();
};

#endif