#include <iostream>

#include "cell.h"

using namespace std;

Cell::Cell() { }

Cell::Cell(char shape) {
	m_Shape = shape;
}

Cell::~Cell() { }

void Cell::printCell() {
	cout << m_Shape << " ";
}

bool Cell::isWall() {
	return false;
}