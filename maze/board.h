#ifndef BOARD_H
#define BOARD_H

#include <vector>

#define BOARD_ROW_SIZE 15 // Must be odd
#define BOARD_COL_SIZE 15 // Must be odd

#define MAX_OFFSET 2
#define MIN_OFFSET -2

class Tile;

class Board {
private:
	int m_RowSize;
	int m_ColSize;

	Tile*** m_Maze;

	std::vector<int> m_PathRow;
	std::vector<int> m_PathCol;
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
	int roundOffset(int offset);

	//=========================================================================
	// Randomized DFS (Recursive Backtracker)
	//=========================================================================
	void randomizedDFS();
	bool hasUnvisitedNeighbour(Tile* curTile);
	Tile** getUnvisitedNeighbour(Tile* curTile);

	//=========================================================================
	// Randomized Prim's Algorithm
	//=========================================================================
	void randomizedPrim();
	void addWalls(Tile* curTile, std::vector<Tile*>& wallList);
	Tile* findUnvisitedWall(Tile* curTile);

	//=========================================================================
	// Wilson's Algorithm
	//=========================================================================
	void wilson();
	Tile** findRandomTile();
	Tile** getNextRandomWalk(Tile* curTile);
};

#endif