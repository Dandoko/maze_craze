#ifndef BOARD_H
#define BOARD_H

#include "tile.h"

class Board {
private:
	int m_RowSize;
	int m_ColSize;

	Tile*** m_Maze;

public:
	Board();
	Board(const Board&) = delete;
	virtual ~Board();

	void printMaze();
	void generateMaze();

};

#endif