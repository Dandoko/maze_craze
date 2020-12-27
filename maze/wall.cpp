#include <iostream>

#include "wall.h"

using namespace std;

Wall::Wall() : Cell(' ') { }

Wall::Wall(bool isBorder) : Cell('X') {
	this->isBorder = isBorder;
}

Wall::~Wall() {}

bool Wall::isWall() {
	return true;
}

bool Wall::getIsBorder() {
	return isBorder;
}