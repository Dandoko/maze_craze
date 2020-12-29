#ifndef SOLVER_H
#define SOLVER_H

#include "unit.h"

class Solver : public Unit {
private:
public:
	Solver();
	Solver(const Solver&) = delete;
	virtual ~Solver();

	bool isSolver();
};

#endif