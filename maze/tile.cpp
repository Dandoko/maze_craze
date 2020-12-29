#include <iostream>

#include "tile.h"

using namespace std;

Tile::Tile() {
	m_Cell = NULL;
	m_Unit = NULL;

	m_X = -1;
	m_Y = -1;
}

Tile::Tile(Cell* cell, int x, int y) {
	m_Cell = cell;
	m_Unit = NULL;

	m_X = x;
	m_Y = y;
}

Tile::~Tile() { }

Cell* Tile::getCell() {
	return m_Cell;
}

void Tile::setCell(Cell* cell) {
	m_Cell = cell;
}

Unit* Tile::getUnit() {
	return m_Unit;
}

void Tile::setUnit(Unit* unit) {
	m_Unit = unit;
}

int Tile::getX() {
	return m_X;
}

int Tile::getY() {
	return m_Y;
}