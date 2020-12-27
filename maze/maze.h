#ifndef MAZE_H
#define MAZE_H

#include "tile.h"

class Maze {
private:
	int rowSize;
	int colSize;

	Tile*** maze;

public:
	Maze();
	virtual ~Maze();

	void printMaze();
	void generateMaze();

};

#endif