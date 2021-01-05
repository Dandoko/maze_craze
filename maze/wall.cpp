#include <iostream>

#include "wall.h"

using namespace std;

Wall::Wall(bool isBorder) : Cell('X') {
	m_IsBorder = isBorder;
}

Wall::~Wall() {}

bool Wall::getIsBorder() {
	return m_IsBorder;
}

bool Wall::isWall() {
	return true;
}