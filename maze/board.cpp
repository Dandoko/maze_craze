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
	m_RowSize = 11;
	m_ColSize = 11;

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

	m_PathLength = 0;
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
		if (m_PathLength > 0 && m_CurPathIndex < m_PathLength) {
			delete m_Maze[m_PathRow[m_CurPathIndex]][m_PathCol[m_CurPathIndex]]->getCell();
			m_Maze[m_PathRow[m_CurPathIndex]][m_PathCol[m_CurPathIndex]]->setCell(new EmptyPath());
			m_Maze[m_PathRow[m_CurPathIndex]][m_PathCol[m_CurPathIndex]]->setUnit(new Creator());

			if (m_CurPathIndex > 0) {
				delete m_Maze[m_PathRow[m_CurPathIndex - 1]][m_PathCol[m_CurPathIndex - 1]]->getUnit();
				m_Maze[m_PathRow[m_CurPathIndex - 1]][m_PathCol[m_CurPathIndex - 1]]->setUnit(NULL);
			}
			
			if (m_CurPathIndex + 1 == m_PathLength) {
				delete m_Maze[m_PathRow[m_CurPathIndex]][m_PathCol[m_CurPathIndex]]->getUnit();
				m_Maze[m_PathRow[m_CurPathIndex]][m_PathCol[m_CurPathIndex]]->setUnit(NULL);
			}

			m_CurPathIndex++;
		}
		else {
			resetMaze();
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

	m_PathLength = 0;
	m_CurPathIndex = 0;
	m_PathCreated = false;
}

void Board::generateMaze() {
	recursiveBacktracker();
}

// @see https://en.wikipedia.org/wiki/Maze_generation_algorithm#Iterative_implementation
void Board::recursiveBacktracker() {
	stack<Tile*> visited;

	// Choose the initial cell, mark it as visited and push it to the stack
	Tile* initialTile = m_Maze[m_RowSize / 2][m_ColSize / 2];
	visited.push(initialTile);
	// While the stack is not empty
	while (!visited.empty()) {
		// Pop a cell from the stack and make it a current cell
		Tile* curTile = visited.top();
		visited.pop();

		m_PathRow[m_PathLength] = curTile->getY();
		m_PathCol[m_PathLength] = curTile->getX();
		m_PathLength++;

		// If the current cell has any neighbours which have not been visited
		if (hasUnvisitedNeighbour(curTile)) {

			// Push the current cell to the stack
			visited.push(curTile);

			// Choose one of the unvisited neighbours
			Tile** unvisitedNeighbour = getUnvisitedNeighbour(curTile);

			// Remove the wall between the current cell and the chosen cell
			m_PathRow[m_PathLength] = unvisitedNeighbour[0]->getY();
			m_PathCol[m_PathLength] = unvisitedNeighbour[0]->getX();
			m_PathLength++;

			// Mark the chosen cell as visited and push it to the stack
			unvisitedNeighbour[1]->getCell()->setIsVisited(true);
			visited.push(unvisitedNeighbour[1]);

			m_PathRow[m_PathLength] = unvisitedNeighbour[1]->getY();
			m_PathCol[m_PathLength] = unvisitedNeighbour[1]->getX();
			m_PathLength++;

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

int Board::roundOffset(int offset) {
	if (offset > 1) return 2;
	else if (offset < -1) return -2;
	return 0;
}