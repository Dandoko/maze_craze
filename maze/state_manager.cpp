#include <iostream>

#include "state_manager.h"
#include "maze.h"
#include "main_menu.h"
#include "manager.h"

StateManager::StateManager(Manager* manager) {
	m_Manager = manager;
	m_State = State::MAIN_MENU;
	m_Maze = new Maze();
	m_MainMenu = new MainMenu(this);
}

StateManager::~StateManager() {}

Manager* StateManager::getManager() {
	return m_Manager;
}

State StateManager::getState() {
	return m_State;
}

void StateManager::setState(State state) {
	m_State = state;
}

Maze* StateManager::getMaze() {
	return m_Maze;
}

MainMenu* StateManager::getMainMenu() {
	return m_MainMenu;
}

void StateManager::update() {
	if (m_State == State::MAIN_MENU) {
		m_MainMenu->update();
	}
	else {
		m_Maze->update();
	}
}

void StateManager::setAlgorithm(int algoNum) {
	m_Maze->setAlgorithm(algoNum);
}