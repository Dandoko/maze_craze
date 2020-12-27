#include <iostream>

#include "cell.h"

using namespace std;

Cell::Cell() { }

Cell::Cell(char shape) {
	this->shape = shape;
}

Cell::~Cell() { }

void Cell::printCell() {
	cout << shape;
}

bool Cell::isWall() {
	return false;
}