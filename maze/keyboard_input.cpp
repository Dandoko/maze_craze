#include <iostream>
#include <windows.h>

#include "keyboard_input.h"

using namespace std;

KeyboardInput::KeyboardInput() {
	m_SpacebarClicked = false;
}

KeyboardInput::~KeyboardInput() {}

bool KeyboardInput::getSpacebarClicked() {
	return m_SpacebarClicked;
}

void KeyboardInput::update() {
	if (GetAsyncKeyState(VK_SPACE)) {
		m_SpacebarClicked = true;
	}
}