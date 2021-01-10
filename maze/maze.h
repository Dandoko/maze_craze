#ifndef MAZE_H
#define MAZE_H

class Board;

enum class MazeState {
	GENERATING,
	SOLVING
};

class Maze {
private:
	Board* m_Board;
	MazeState m_MazeState;
public:
	Maze();
	Maze(const Maze&) = delete;
	virtual ~Maze();

	Board* getBoard();

	void update();
	void render();
};

#endif