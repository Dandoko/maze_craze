#ifndef BOARD_H
#define BOARD_H

#define MAX_OFFSET 2
#define MIN_OFFSET -2

class Tile;

class Board {
private:
	int m_RowSize;
	int m_ColSize;

	Tile*** m_Maze;

	int m_PathRow[500];
	int m_PathCol[500];
	int m_PathLength;
	int m_CurPathIndex;
	bool m_PathCreated;

public:
	Board();
	Board(const Board&) = delete;
	virtual ~Board();

	void printMaze();
	void update();
	void generateMaze();
	void recursiveBacktracker();
	bool hasUnvisitedNeighbour(Tile* curTile);
	Tile** getUnvisitedNeighbour(Tile* curTile);
private:
	int roundOffset(int offset);
};

#endif