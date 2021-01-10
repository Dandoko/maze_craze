#include <iostream>

#include "state_manager.h"
#include "maze.h"

StateManager::StateManager() {
	m_Maze = new Maze();
}

StateManager::~StateManager() {}

Maze* StateManager::getMaze() {
	return m_Maze;
}