#include <iostream>

#include "state_manager.h"
#include "maze.h"
#include "main_menu.h"

enum State {
	MAIN_MENU,
	GENERATE,
	SOLVE
};

StateManager::StateManager() {
	m_State = GENERATE;
	m_Maze = new Maze();
	m_MainMenu = new MainMenu();
}

StateManager::~StateManager() {}

Maze* StateManager::getMaze() {
	return m_Maze;
}

void StateManager::update() {
	m_Maze->update();
}