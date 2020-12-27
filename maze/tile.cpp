#include <iostream>

#include "tile.h"

using namespace std;

Tile::Tile() {
	cell = NULL;
}

Tile::Tile(bool isBorder) {
	Wall* wall = new Wall(isBorder);
	cell = (Cell*)wall;
}

Tile::~Tile() { }

Cell* Tile::getCell() {
	return cell;
}