#include <iostream>

#include "wall.h"

using namespace std;

Wall::Wall() : Cell(' ') { }

Wall::Wall(bool isBorder) : Cell('X') {
	m_IsBorder = isBorder;
}

Wall::~Wall() {}

bool Wall::isWall() {
	return true;
}

bool Wall::getIsBorder() {
	return m_IsBorder;
}