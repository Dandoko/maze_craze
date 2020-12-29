#include <iostream>

#include "solver.h"

using namespace std;

Solver::Solver() : Unit('S') {

}

Solver::~Solver() {}

bool Solver::isSolver() {
	return true;
}