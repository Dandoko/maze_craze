#include <iostream>

#include "manager.h"

using namespace std;

Manager* Manager::sManagerInstance = NULL;

Manager::Manager() {
	m_Maze = new Maze();
	m_Loop = new Loop(m_Maze);
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
