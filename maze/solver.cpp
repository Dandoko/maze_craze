#include <iostream>

#include "solver.h"

using namespace std;

Solver::Solver(char shape) : Unit(shape) {

}

Solver::~Solver() {}

bool Solver::isSolver() {
	return true;
}