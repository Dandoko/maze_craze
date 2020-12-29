#ifndef BOARD_H
#define BOARD_H

#include <vector>

#define BOARD_ROW_SIZE 15
#define BOARD_COL_SIZE 15

#define MAX_OFFSET 2
#define MIN_OFFSET -2

class Tile;

class Board {
private:
	int m_RowSize;
	int m_ColSize;

	Tile*** m_Maze;

	//=========================================================================
	// Randomized DFS (Recursive Backtracker)
	//=========================================================================
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
	void resetMaze();
	void generateMaze();

	//=========================================================================
	// Randomized DFS (Recursive Backtracker)
	//=========================================================================
	void randomizedDFS();
	bool hasUnvisitedNeighbour(Tile* curTile);
	Tile** getUnvisitedNeighbour(Tile* curTile);
	int roundOffset(int offset);

	//=========================================================================
	// Randomized Prim
	//=========================================================================
	void randomizedPrim();
	void addWalls(Tile* curTile, std::vector<Tile*>& wallList);
	Tile* findUnvisitedWall(Tile* curTile);
};

#endif