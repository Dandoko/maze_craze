#ifndef TILE_H
#define TILE_H

#include "cell.h"
#include "wall.h"
#include "unit.h"

class Tile {
private:
	Cell* m_Cell;
	Unit* m_Unit;
public:
	Tile();
	Tile(const Tile&) = delete;
	Tile(bool isBorder);
	virtual ~Tile();

	Cell* getCell();
};

#endif TILE_H