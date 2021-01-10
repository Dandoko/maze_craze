#include <iostream>

#include "manager.h"
#include "loop.h"
#include "keyboard_input.h"
#include "renderer.h"
#include "state_manager.h"
#include "maze.h"

using namespace std;

Manager* Manager::sManagerInstance = NULL;

Manager::Manager() {
	m_KeyboardInput = new KeyboardInput();
	m_StateManager = new StateManager();

	m_Loop = new Loop(this);
	m_Renderer = new Renderer(this);
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

StateManager* Manager::getStateManager() {
	return m_StateManager;
}

void Manager::start() {
	m_Loop->start();
}

void Manager::update() {
	if (m_KeyboardInput->getSpacebarClicked()) m_StateManager->getMaze()->update();
	m_KeyboardInput->update();
}

void Manager::render() {
	m_Renderer->render();
}
