#include <iostream>

#include "manager.h"
#include "maze.h"
#include "loop.h"
#include "keyboard_input.h"

using namespace std;

Manager* Manager::sManagerInstance = NULL;

Manager::Manager() {
	m_Maze = new Maze();
	m_Loop = new Loop(this);
	m_KeyboardInput = new KeyboardInput();
}

Manager::~Manager() {}

Manager* Manager::getManagerInstance() {
	if (!sManagerInstance) sManagerInstance = new Manager();

	return sManagerInstance;
}

void Manager::destoryManagerInstance() {
	delete sManagerInstance;
	sManagerInstance = NULL;
}

void Manager::start() {
	m_Loop->start();
}

void Manager::update() {
	if (m_KeyboardInput->getSpacebarClicked()) m_Maze->update();
	m_KeyboardInput->update();
}

void Manager::render() {
	m_Maze->render();
}
