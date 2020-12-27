#ifndef TILE_H
#define TILE_H

#include "cell.h"
#include "wall.h"

class Tile {
private:
	Cell* cell;
public:
	Tile();
	Tile(bool isBorder);
	virtual ~Tile();

	Cell* getCell();
};

#endif TILE_H