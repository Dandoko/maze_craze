#ifndef MAZE_H
#define MAZE_H

#include "board.h"

class Maze {
private:
	Board* m_Board;
public:
	Maze();
	Maze(const Maze&) = delete;
	virtual ~Maze();

	Board* getBoard();
};

#endif