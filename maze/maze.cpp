#include <iostream>

#include "maze.h"

using namespace std;

Maze::Maze() {
	m_Board = new Board();
}

Maze::~Maze() {
	delete m_Board;
}

Board* Maze::getBoard() {
	return m_Board;
}