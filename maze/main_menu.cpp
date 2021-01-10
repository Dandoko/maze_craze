#include <iostream>

#include "main_menu.h"
#include "state_manager.h"
#include "manager.h"
#include "keyboard_input.h"

using namespace std;

MainMenu::MainMenu(StateManager* stateManager) {
	m_StateManager = stateManager;
	m_MainMenuState = MainMenuState::WELCOME;
}

MainMenu::~MainMenu() {}

void MainMenu::render() {
	cout << endl;
	cout << "\t\tWelcome to Maze Craze!";
	cout << endl << endl << endl;

	if (m_MainMenuState == MainMenuState::WELCOME) {
		cout << "\t\tPress the \"a\" key to continue!" << endl;
	}
	else {
		cout << "\t\tMaze Generation" << endl;
		cout << "\t\tSelect a maze type you want to generate!" << endl << endl;

		cout << "\t\t1. Test Algorithm" << endl;
	}
}

void MainMenu::update() {
	if (m_MainMenuState == MainMenuState::WELCOME) {
		char testA;
		cin >> testA;

		if (testA == 'a') {
			m_MainMenuState = MainMenuState::SELECT;
		}
	}
	else {
		char test1;
		cin >> test1;

		if (test1 == '1') {
			m_StateManager->setState(State::MAZE);
		}
	}
}