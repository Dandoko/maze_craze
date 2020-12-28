#include <iostream>

#include "unit.h"

using namespace std;

Unit::Unit(char shape) {
	m_Shape = shape;
}

Unit::~Unit() { }

void Unit::printUnit() {
	cout << m_Shape << " ";
}

bool Unit::isSolver() {
	return false;
}

bool Unit::isCreator() {
	return false;
}