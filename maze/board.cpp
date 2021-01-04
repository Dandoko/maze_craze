#include <iostream>
#include <stack>

#include "board.h"
#include "tile.h"
#include "wall.h"
#include "empty_path.h"
#include "unit.h"
#include "creator.h"

using namespace std;

Board::Board() {
	m_RowSize = BOARD_ROW_SIZE;
	m_ColSize = BOARD_COL_SIZE;

	m_Maze = new Tile** [m_RowSize];
	for (int i = 0; i < m_RowSize; i++) {
		m_Maze[i] = new Tile* [m_ColSize];
	}

	for (int i = 0; i < m_RowSize; i++) {
		for (int j = 0; j < m_ColSize; j++) {
			bool isBorder = (i == 0 || i == m_RowSize - 1 || j == 0 || j == m_ColSize - 1) ? true : false;
			m_Maze[i][j] = new Tile(new Wall(isBorder), j, i);
		}
	}

	m_CurPathIndex = 0;
	m_PathCreated = false;
}

Board::~Board() {
	for (int i = 0; i < m_RowSize; i++) {
		for (int j = 0; j < m_ColSize; j++) {;
			delete m_Maze[i][j];
			m_Maze[i][j] = NULL;
		}
	}

	for (int i = 0; i < m_RowSize; i++) {
		delete *m_Maze[i];
		*m_Maze[i] = NULL;
	}

	delete *m_Maze;
	*m_Maze = NULL;
}

void Board::printMaze() {
	cout << endl;
	for (int i = 0; i < m_RowSize; i++) {
		cout << "   ";
		for (int j = 0; j < m_ColSize; j++) {
			if (m_Maze[i][j]->getUnit()) {
				m_Maze[i][j]->getUnit()->printUnit();
			}
			else if (m_Maze[i][j]->getCell()) {
				m_Maze[i][j]->getCell()->printCell();
			}
		}
		cout << endl;
	}
}

void Board::update() {
	if (!m_PathCreated) {
		generateMaze();
		m_PathCreated = true;
	}
	else {
		if (m_PathRow.size() > 0 && m_CurPathIndex < m_PathRow.size()) {
			if (m_CurPathIndex > 0 && m_DeleteWilsonLoop.size() > 0 && m_DeleteWilsonLoop.find(m_CurPathIndex) != m_DeleteWilsonLoop.end()) {
				for (int i = 0; i < m_DeleteWilsonLoop[m_CurPathIndex].size(); i++) {
					delete m_DeleteWilsonLoop[m_CurPathIndex].at(i)->getCell();
					m_DeleteWilsonLoop[m_CurPathIndex].at(i)->setCell(new Wall(false));
				}
			}

			delete m_Maze[m_PathRow.at(m_CurPathIndex)][m_PathCol.at(m_CurPathIndex)]->getCell();
			m_Maze[m_PathRow.at(m_CurPathIndex)][m_PathCol.at(m_CurPathIndex)]->setCell(new EmptyPath());
			m_Maze[m_PathRow.at(m_CurPathIndex)][m_PathCol.at(m_CurPathIndex)]->setUnit(new Creator());

			if (m_CurPathIndex > 0) {
				delete m_Maze[m_PathRow.at(m_CurPathIndex - 1)][m_PathCol.at(m_CurPathIndex - 1)]->getUnit();
				m_Maze[m_PathRow.at(m_CurPathIndex - 1)][m_PathCol.at(m_CurPathIndex - 1)]->setUnit(NULL);
			}

			if (m_CurPathIndex + 1 == m_PathRow.size()) {
				delete m_Maze[m_PathRow.at(m_CurPathIndex)][m_PathCol.at(m_CurPathIndex)]->getUnit();
				m_Maze[m_PathRow.at(m_CurPathIndex)][m_PathCol.at(m_CurPathIndex)]->setUnit(NULL);
			}

			m_CurPathIndex++;
		}
		else {
			//resetMaze();
		}
	}
}

void Board::resetMaze() {
	for (int i = 0; i < m_RowSize; i++) {
		for (int j = 0; j < m_ColSize; j++) {
			delete m_Maze[i][j]->getUnit();
			m_Maze[i][j]->setUnit(NULL);

			if (!m_Maze[i][j]->getCell()->isWall()) {
				delete m_Maze[i][j]->getCell();

				bool isBorder = (i == 0 || i == m_RowSize - 1 || j == 0 || j == m_ColSize - 1) ? true : false;
				m_Maze[i][j]->setCell(new Wall(isBorder));
			}
		}
	}
	m_PathRow.clear();
	m_PathCol.clear();
	m_CurPathIndex = 0;
	m_PathCreated = false;
	m_DeleteWilsonLoop.clear();
}

void Board::generateMaze() {
	//randomizedDFS();
	//randomizedPrim();
	//wilson();
	recursiveDivision();
}

int Board::roundOffset(int offset) {
	if (offset > 1) return 2;
	else if (offset < -1) return -2;
	return 0;
}

//=============================================================================
//=============================================================================
// Randomized DFS (Recursive Backtracker)
//=============================================================================
//=============================================================================

// @see https://en.wikipedia.org/wiki/Maze_generation_algorithm#Iterative_implementation
void Board::randomizedDFS() {
	stack<Tile*> visited;

	// Choose the initial cell, mark it as visited and push it to the stack
	Tile* initialTile = m_Maze[m_RowSize / 2][m_ColSize / 2];
	visited.push(initialTile);

	// While the stack is not empty
	while (!visited.empty()) {

		// Pop a cell from the stack and make it a current cell
		Tile* curTile = visited.top();
		visited.pop();

		m_PathRow.push_back(curTile->getY());
		m_PathCol.push_back(curTile->getX());

		// If the current cell has any neighbours which have not been visited
		if (hasUnvisitedNeighbour(curTile)) {

			// Push the current cell to the stack
			visited.push(curTile);

			// Choose one of the unvisited neighbours
			Tile** unvisitedNeighbour = getUnvisitedNeighbour(curTile);

			// Remove the wall between the current cell and the chosen cell
			m_PathRow.push_back(unvisitedNeighbour[0]->getY());
			m_PathCol.push_back(unvisitedNeighbour[0]->getX());

			// Mark the chosen cell as visited and push it to the stack
			unvisitedNeighbour[1]->getCell()->setIsVisited(true);
			visited.push(unvisitedNeighbour[1]);

			m_PathRow.push_back(unvisitedNeighbour[1]->getY());
			m_PathCol.push_back(unvisitedNeighbour[1]->getX());

			delete[] unvisitedNeighbour;
			unvisitedNeighbour = NULL;
		}
	}
}

bool Board::hasUnvisitedNeighbour(Tile* curTile) {
	for (int i = -2; i <= 2; i += 2) {
		for (int j = -2; j <= 2; j += 2) {
			if (i != 0 || j != 0) {
				if (!(i / 2 && j / 2)) {
					if (curTile->getX() + j >= 1 && curTile->getY() + i >= 1 &&
						curTile->getX() + j < m_ColSize - 1 && curTile->getY() + i < m_RowSize - 1 &&
						!m_Maze[curTile->getY() + i][curTile->getX() + j]->getCell()->getIsVisited()) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

// Pre: There must be at least 1 unvisited neighbour
// Post: Returns the between neighbour as the first index and the outside neighbour as the second index
Tile** Board::getUnvisitedNeighbour(Tile* curTile) {
	Tile** neighbours = new Tile * [2];
	Tile* unvisitedNeighbour = NULL;
	Tile* betweenNeighbour = NULL;

	while (!unvisitedNeighbour) {
		int xOffset = roundOffset(rand() % (MAX_OFFSET - MIN_OFFSET + 1) + MIN_OFFSET);
		int yOffset = roundOffset(rand() % (MAX_OFFSET - MIN_OFFSET + 1) + MIN_OFFSET);

		if (yOffset != 0 || xOffset != 0) {
			if (!(yOffset / 2 && xOffset / 2)) {
				if (curTile->getX() + xOffset >= 1 && curTile->getY() + yOffset >= 1 &&
					curTile->getX() + xOffset < m_ColSize - 1 && curTile->getY() + yOffset < m_RowSize - 1 &&
					!m_Maze[curTile->getY() + yOffset][curTile->getX() + xOffset]->getCell()->getIsVisited()) {
					unvisitedNeighbour = m_Maze[curTile->getY() + yOffset][curTile->getX() + xOffset];
					betweenNeighbour = m_Maze[curTile->getY() + yOffset / 2][curTile->getX() + xOffset / 2];
				}
			}
		}
	}

	neighbours[0] = betweenNeighbour;
	neighbours[1] = unvisitedNeighbour;

	return neighbours;
}

//=============================================================================
//=============================================================================
// Prim's Algorithm
//=============================================================================
//=============================================================================

// @see https://en.wikipedia.org/wiki/Maze_generation_algorithm#Randomized_Prim's_algorithm
void Board::randomizedPrim() {
	// Start with a grid full of walls.
	vector<Tile*> wallList;

	// Pick a cell, mark it as part of the maze. Add the walls of the cell to the wall list.
	Tile* initialTile = m_Maze[m_RowSize / 2][m_ColSize / 2];
	initialTile->getCell()->setIsVisited(true);
	addWalls(initialTile, wallList);
	m_PathRow.push_back(initialTile->getY());
	m_PathCol.push_back(initialTile->getX());
	
	// While there are walls in the list :
	while (wallList.size() > 0) {
		// Pick a random wall from the list. If only one of the two cells that the wall divides is visited, then :
		int randomIndex = rand() % wallList.size();
		Tile* randomWall = wallList.at(randomIndex);

		Tile* univisitedWall = findUnvisitedWall(randomWall);
		if (univisitedWall) {

			// Make the wall a passage and mark the unvisited cell as part of the maze.
			randomWall->getCell()->setIsVisited(true);
			m_PathRow.push_back(randomWall->getY());
			m_PathCol.push_back(randomWall->getX());

			univisitedWall->getCell()->setIsVisited(true);
			m_PathRow.push_back(univisitedWall->getY());
			m_PathCol.push_back(univisitedWall->getX());

			// Add the neighboring walls of the cell to the wall list.
			addWalls(univisitedWall, wallList);
		}

		// Remove the wall from the list.
		wallList.erase(wallList.begin() + randomIndex);
	}
}

void Board::addWalls(Tile* curTile, vector<Tile*>& wallList) {
	for (int i = -1; i <= 1; i ++) {
		for (int j = -1; j <= 1; j ++) {
			if (i != 0 || j != 0) {
				if (!(i && j)) {
					if (curTile->getX() + j >= 1 && curTile->getY() + i >= 1 &&
						curTile->getX() + j < m_ColSize - 1 && curTile->getY() + i < m_RowSize - 1 &&
						m_Maze[curTile->getY() + i][curTile->getX() + j]->getCell()->isWall()) {

						Tile* curWall = m_Maze[curTile->getY() + i][curTile->getX() + j];
						wallList.push_back(curWall);
					}
				}
			}
		}
	}
}

Tile* Board::findUnvisitedWall(Tile* curTile) {
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (!(i == 0 && j == 0)) {
				if (!(i && j)) {
					if (curTile->getX() + j >= 1 && curTile->getY() + i >= 1 &&
						curTile->getX() + j < m_ColSize - 1 && curTile->getY() + i < m_RowSize - 1 &&
						m_Maze[curTile->getY() + i][curTile->getX() + j]->getCell()->getIsVisited()) {

						int oppositeOffsetI = i * -1;
						int oppositeOffsetJ = j * -1;
						if (curTile->getX() + oppositeOffsetJ >= 1 && curTile->getY() + oppositeOffsetI >= 1 &&
							curTile->getX() + oppositeOffsetJ < m_ColSize - 1 && curTile->getY() + oppositeOffsetI < m_RowSize - 1) {
							if (!m_Maze[curTile->getY() + oppositeOffsetI][curTile->getX() + oppositeOffsetJ]->getCell()->getIsVisited()) {
								return m_Maze[curTile->getY() + oppositeOffsetI][curTile->getX() + oppositeOffsetJ];
							}
						}
					}
				}
			}
		}
	}

	return NULL;
}

//=============================================================================
//=============================================================================
// Wilson's Algorithm
//=============================================================================
//=============================================================================

// @see https://en.wikipedia.org/wiki/Maze_generation_algorithm#Wilson's_algorithm
void Board::wilson() {
	map<Tile*, bool> inMaze;
	map<Tile*, bool> inCurWalk;
	vector<Tile*> inCurWalkOrder;
	int mainTileCount = 0;

	// We begin the algorithm by initializing the maze with one cell chosen arbitrarily.
	Tile** initialTile = findRandomTile();
	inMaze[initialTile[1]] = true;
	initialTile[1]->getCell()->setIsVisited(true);
	mainTileCount++;
	m_PathRow.push_back(initialTile[1]->getY());
	m_PathCol.push_back(initialTile[1]->getX());

	delete[] initialTile;

	// Then we start at a new cell chosen arbitrarily, and perform a random walk until we reach a cell already in the maze.
	Tile** curWalkTiles = new Tile * [2];
	curWalkTiles[0] = NULL;
	curWalkTiles[1] = NULL;
	bool foundLoop = false;
	
	while (mainTileCount < ((BOARD_COL_SIZE - 2) / 2 + 1) * ((BOARD_COL_SIZE - 2) / 2 + 1)) {
		if (!foundLoop) curWalkTiles = findRandomTile();

		while (inMaze.find(curWalkTiles[1]) == inMaze.end() && inCurWalk.find(curWalkTiles[1]) == inCurWalk.end()) {

			inCurWalk[curWalkTiles[0]] = true;
			inCurWalk[curWalkTiles[1]] = true;

			inCurWalkOrder.push_back(curWalkTiles[0]);
			inCurWalkOrder.push_back(curWalkTiles[1]);

			m_PathRow.push_back(curWalkTiles[0]->getY());
			m_PathCol.push_back(curWalkTiles[0]->getX());

			m_PathRow.push_back(curWalkTiles[1]->getY());
			m_PathCol.push_back(curWalkTiles[1]->getX());
			
			Tile* tempWalkTile = curWalkTiles[1];
			delete[] curWalkTiles;
			curWalkTiles = getNextRandomWalk(tempWalkTile);
		}

		// If at any point the random walk reaches its own path, forming a loop, we erase the loop from the path before proceeding.
		if (inCurWalk.find(curWalkTiles[1]) != inCurWalk.end()) {
			
			inCurWalk[curWalkTiles[0]] = true;
			inCurWalkOrder.push_back(curWalkTiles[0]);

			m_PathRow.push_back(curWalkTiles[0]->getY());
			m_PathCol.push_back(curWalkTiles[0]->getX());

			// Finding all of tiles that are a part of the loop
			int loopIndex = -1;
			for (int i = 0; i < inCurWalkOrder.size() && loopIndex == -1; i++) {
				if (inCurWalkOrder.at(i) == curWalkTiles[1]) {
					loopIndex = i;
				}
			}

			// Adding the looped paths to return to walls
			int curPathIndex = m_PathCol.size();
			if (m_DeleteWilsonLoop.find(curPathIndex) == m_DeleteWilsonLoop.end()) {
				vector<Tile*> loopToErase;
				m_DeleteWilsonLoop[curPathIndex] = loopToErase;
			}

			// Removing all the tiles in the loop starting from the tile after the loop point
			for (int i = inCurWalkOrder.size() - 1; i > loopIndex; i--) {
				m_DeleteWilsonLoop[curPathIndex].push_back(inCurWalkOrder.at(i));
				inCurWalkOrder.at(i)->getCell()->setIsVisited(false);
				inCurWalk.erase(inCurWalkOrder.at(i));
				inCurWalkOrder.erase(inCurWalkOrder.begin() + i);
			}

			Tile* lastTileOnLoop = inCurWalkOrder.at(loopIndex);
			m_PathRow.push_back(lastTileOnLoop->getY());
			m_PathCol.push_back(lastTileOnLoop->getX());

			delete[] curWalkTiles;
			curWalkTiles = getNextRandomWalk(lastTileOnLoop);

			foundLoop = true;
		}
		// When the path reaches the maze, we add it to the maze.
		else if (inMaze.find(curWalkTiles[1]) != inMaze.end()) {
			
			inCurWalk[curWalkTiles[0]] = true;
			inCurWalkOrder.push_back(curWalkTiles[0]);

			m_PathRow.push_back(curWalkTiles[0]->getY());
			m_PathCol.push_back(curWalkTiles[0]->getX());

			m_PathRow.push_back(curWalkTiles[1]->getY());
			m_PathCol.push_back(curWalkTiles[1]->getX());

			for (int i = 0; i < inCurWalkOrder.size(); i++) {
				inCurWalkOrder.at(i)->getCell()->setIsVisited(true);
				inMaze[inCurWalkOrder.at(i)] = true;

				if (inCurWalkOrder.at(i)->getX() % 2 != 0 && inCurWalkOrder.at(i)->getY() % 2 != 0)
					mainTileCount++;
			}
			inCurWalk.clear();
			inCurWalkOrder.clear();
			foundLoop = false;
		}

		// Then we perform another loop - erased random walk from another arbitrary starting cell, repeating until all cells have been filled.
	}

	delete[] curWalkTiles;
}

// Pre: There must be at least 1 valid tile to find
// Post: Only odd indices will be found
Tile** Board::findRandomTile() {
	Tile** randTiles = new Tile * [2];
	randTiles[0] = NULL;
	randTiles[1] = NULL;

	while (!randTiles[1]) {
		int randomX = rand() % (BOARD_ROW_SIZE - 2) + 1;
		int randomY = rand() % (BOARD_COL_SIZE - 2) + 1;
		
		if (randomX % 2 != 0 && randomY % 2 != 0) {
			if (!m_Maze[randomY][randomX]->getCell()->getIsVisited()) {
				randTiles[1] = m_Maze[randomY][randomX];

				while (!randTiles[0]) {
					int xOffset = roundOffset(rand() % (MAX_OFFSET - MIN_OFFSET + 1) + MIN_OFFSET);
					int yOffset = roundOffset(rand() % (MAX_OFFSET - MIN_OFFSET + 1) + MIN_OFFSET);

					if (yOffset != 0 || xOffset != 0) {
						if (!(yOffset / 2 && xOffset / 2)) {
							if (randTiles[1]->getX() + xOffset >= 1 && randTiles[1]->getY() + yOffset >= 1 &&
								randTiles[1]->getX() + xOffset < m_ColSize - 1 && randTiles[1]->getY() + yOffset < m_RowSize - 1) {
								randTiles[0] = m_Maze[randTiles[1]->getY() + yOffset / 2][randTiles[1]->getX() + xOffset / 2];
							}
						}
					}
				}
			}
		}
	}

	return randTiles;
}

Tile** Board::getNextRandomWalk(Tile* curTile) {
	Tile** nextWalkTiles = new Tile * [2];
	nextWalkTiles[0] = NULL;
	nextWalkTiles[1] = NULL;

	while (!nextWalkTiles[1]) {
		int xOffset = roundOffset(rand() % (MAX_OFFSET - MIN_OFFSET + 1) + MIN_OFFSET);
		int yOffset = roundOffset(rand() % (MAX_OFFSET - MIN_OFFSET + 1) + MIN_OFFSET);

		if (yOffset != 0 || xOffset != 0) {
			if (!(yOffset / 2 && xOffset / 2)) {
				if (curTile->getX() + xOffset >= 1 && curTile->getY() + yOffset >= 1 &&
					curTile->getX() + xOffset < m_ColSize - 1 && curTile->getY() + yOffset < m_RowSize - 1) {
					nextWalkTiles[0] = m_Maze[curTile->getY() + yOffset / 2][curTile->getX() + xOffset / 2];
					nextWalkTiles[1] = m_Maze[curTile->getY() + yOffset][curTile->getX() + xOffset];
				}
			}
		}
	}

	return nextWalkTiles;
}

//=============================================================================
//=============================================================================
// Recursive Division
//=============================================================================
//=============================================================================

// @see https://en.wikipedia.org/wiki/Maze_generation_algorithm#Recursive_division_method
void Board::recursiveDivision() {
	// Begin with the maze's space with no walls. Call this a chamber.
	
	divide(1, BOARD_COL_SIZE - 2, 1, BOARD_ROW_SIZE);

	//cout << "END" << endl;
	//exit(0);
}

void Board::divide(int minX, int maxX, int minY, int maxY) {
	if (maxX - minX <= 2 || maxY - minY <= 2) {
		return;
	}

	// Divide the chamber with a randomly positioned wall (or multiple walls) where
	// each wall contains a randomly positioned passage opening within it.
	int* chamber = createChamber(minX, maxX, minY, maxY);

	// Then recursively repeat the process on the subchambers until all chambers are minimum sized.
	if (chamber[0] == DIR_N || chamber[0] == DIR_S) {
		divide(minX, chamber[1], minY, maxY);
		divide(chamber[1], maxX, minY, maxY);
	}
	else {
		divide(minX, maxX, minY, chamber[1]);
		divide(minX, maxX, chamber[1], maxY);
	}

	delete[] chamber;
}

// Post: Returns dir, randPos depending on direction
int* Board::createChamber(int minX, int maxX, int minY, int maxY) {
	int randDir = rand() % 4;

	int randPosX = rand() % (maxX - minX) + minX;
	int randPosY = rand() % (maxY - minY) + minY;
	while (randPosX % 2 != 1 && randPosY % 2 != 1) {
		randPosX = rand() % (maxX - minX) + minX;
		randPosY = rand() % (maxY - minY) + minY;
	}

	int randPos = -1;
	if (randDir == DIR_N || randDir == DIR_S) {
		for (int i = minY; i <= maxY; i++) {
			if (i != randPosY) {
				m_PathRow.push_back(randPosX);
				m_PathCol.push_back(i);
			}
		}
		randPos = randPosX;
	}
	else if (randDir == DIR_E || randDir == DIR_W) {
		for (int j = minX; j <= maxX; j++) {
			if (j != randPosX) {
				m_PathRow.push_back(j);
				m_PathCol.push_back(randPosY);
			}
		}
		randPos = randPosY;
	}

	int* chamber = new int [2];
	chamber[0] = randDir;
	chamber[1] = randPos;
	return chamber;
}