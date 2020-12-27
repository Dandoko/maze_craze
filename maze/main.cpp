#include <iostream>

#include "maze.h"

using namespace std;

int main() {

	Maze *maze = new Maze();
	maze->generateMaze();

	return 0;
}