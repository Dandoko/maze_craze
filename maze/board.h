#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <map>

#define BOARD_ROW_SIZE 15 // Must be odd
#define BOARD_COL_SIZE 15 // Must be odd

#define MAX_OFFSET 2
#define MIN_OFFSET -2

#define DIR_N 0
#define DIR_E 1
#define DIR_S 2
#define DIR_W 3

#define RECURSIVE_DIVISION_ON

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

	//=========================================================================
	// Wilson's Algorithm
	//=========================================================================
	std::map<int, std::vector<Tile*>> m_DeleteWilsonLoop;

public:
	Board();
	Board(const Board&) = delete;
	virtual ~Board();

	void printMaze();
	void update();
	void resetMaze();
	void emptyMaze();
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

	//=========================================================================
	// Recursive Division
	//=========================================================================
	void recursiveDivision();
	void divide(int minX, int maxX, int minY, int maxY);
	int* createChamber(int minX, int maxX, int minY, int maxY);
};

#endif