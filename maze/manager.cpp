#include <iostream>

#include "manager.h"
#include "maze.h"
#include "loop.h"

using namespace std;

Manager* Manager::sManagerInstance = NULL;

Manager::Manager() {
	m_Maze = new Maze();
	m_Loop = new Loop(this);
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
	m_Maze->update();
}

void Manager::render() {
	m_Maze->render();
}
