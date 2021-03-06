#include <iostream>

#include "maze.h"
#include "board.h"

using namespace std;

Maze::Maze() {
	m_Board = new Board();
	m_MazeState = MazeState::GENERATING;
}

Maze::~Maze() {
	delete m_Board;
}

Board* Maze::getBoard() {
	return m_Board;
}

void Maze::update() {
	m_Board->update();
}

void Maze::render() {
	m_Board->printMaze();
}

void Maze::setAlgorithm(int algoNum) {
	m_Board->setAlgorithm(algoNum);
}