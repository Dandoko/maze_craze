#ifndef TILE_H
#define TILE_H

class Cell;
class Unit;

class Tile {
private:
	Cell* m_Cell;
	Unit* m_Unit;

	int m_X;
	int m_Y;
public:
	Tile();
	Tile(Cell* cell, int x, int y);
	Tile(const Tile&) = delete;
	virtual ~Tile();

	Cell* getCell();
	void setCell(Cell* cell);

	int getX();
	int getY();
};

#endif TILE_H