#ifndef MAZE_H
#define MAZE_H

class Board;

class Maze {
private:
	Board* m_Board;
public:
	Maze();
	Maze(const Maze&) = delete;
	virtual ~Maze();

	Board* getBoard();

	void update();
	void render();
};

#endif