#include <iostream>

#include "cell.h"

using namespace std;

Cell::Cell(char shape) {
	m_Shape = shape;
	m_IsVisited = false;
}

Cell::~Cell() { }

void Cell::printCell() {
	cout << m_Shape << " ";
}

bool Cell::getIsVisited() {
	return m_IsVisited;
}

void Cell::setIsVisited(bool isVisited) {
	m_IsVisited = isVisited;
}

bool Cell::isWall() {
	return false;
}

bool Cell::isPath() {
	return false;
}