#include <iostream>
#include <windows.h>

#include "keyboard_input.h"

using namespace std;

KeyboardInput::KeyboardInput() {
	m_SpacebarClicked = false;
}

KeyboardInput::~KeyboardInput() {}

void KeyboardInput::update() {
	if (GetAsyncKeyState(VK_SPACE)) {
		m_SpacebarClicked = true;
	}
}

bool KeyboardInput::getSpacebarClicked() {
	return m_SpacebarClicked;
}