#include <iostream>

#include "maze.h"

using namespace std;

Maze::Maze() {
	rowSize = 15;
	colSize = 15;

	maze = new Tile ** [rowSize];
	for (int i = 0; i < rowSize; i++) {
		maze[i] = new Tile * [colSize];
	}

	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			bool isBorder = (i == 0 || i == rowSize - 1 || j == 0 || j == colSize - 1) ? true : false;
			maze[i][j] = new Tile(isBorder);
		}
	}
}

Maze::~Maze() {}

void Maze::printMaze() {
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (maze[i][j]->getCell()->isWall()) {
				maze[i][j]->getCell()->printCell();
			}
		}
		cout << endl;
	}
}

void Maze::generateMaze() {
	printMaze();
}