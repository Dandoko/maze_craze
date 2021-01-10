#include <iostream>

#include "renderer.h"
#include "manager.h"
#include "state_manager.h"
#include "maze.h"

Renderer::Renderer(Manager* manager) {
	m_Manager = manager;
}

Renderer::~Renderer() {}

void Renderer::render() {
	m_Manager->getStateManager()->getMaze()->render();
}