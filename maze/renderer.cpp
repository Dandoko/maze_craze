#include <iostream>

#include "renderer.h"
#include "manager.h"
#include "state_manager.h"
#include "maze.h"
#include "main_menu.h"

using namespace std;

Renderer::Renderer(Manager* manager) {
	m_Manager = manager;
}

Renderer::~Renderer() {}

void Renderer::render() {
	if (m_Manager->getStateManager()->getState() == State::MAIN_MENU) {
		m_Manager->getStateManager()->getMainMenu()->render();
	}
	else {
		m_Manager->getStateManager()->getMaze()->render();
	}
}