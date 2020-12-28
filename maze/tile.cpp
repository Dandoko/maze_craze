#include <iostream>

#include "tile.h"

using namespace std;

Tile::Tile() {
	m_Cell = NULL;
	m_Unit = NULL;
}

Tile::Tile(bool isBorder) {
	Wall* wall = new Wall(isBorder);
	m_Cell = (Cell*)wall;

	m_Unit = NULL;
}

Tile::~Tile() { }

Cell* Tile::getCell() {
	return m_Cell;
}