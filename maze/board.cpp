#include <iostream>

#include "board.h"

using namespace std;

Board::Board() {
	m_RowSize = 15;
	m_ColSize = 15;

	m_Maze = new Tile** [m_RowSize];
	for (int i = 0; i < m_RowSize; i++) {
		m_Maze[i] = new Tile* [m_ColSize];
	}

	for (int i = 0; i < m_RowSize; i++) {
		for (int j = 0; j < m_ColSize; j++) {
			bool isBorder = (i == 0 || i == m_RowSize - 1 || j == 0 || j == m_ColSize - 1) ? true : false;
			m_Maze[i][j] = new Tile(isBorder);
		}
	}
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
			if (m_Maze[i][j]->getCell()->isWall()) {
				m_Maze[i][j]->getCell()->printCell();
			}
		}
		cout << endl;
	}
}

void Board::generateMaze() {
	printMaze();
}