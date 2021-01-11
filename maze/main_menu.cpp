#include <iostream>

#include "main_menu.h"
#include "state_manager.h"

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

		cout << "\t\t1. Randomized DFS (Recursive Backtracker)" << endl;
		cout << "\t\t2. Randomized Prim's Algorithm" << endl;
		cout << "\t\t3. Wilson's Algorithm" << endl;
		cout << "\t\t4. Recursive Division" << endl;
	}
}

void MainMenu::update() {
	if (m_MainMenuState == MainMenuState::WELCOME) {
		char startA;
		cin >> startA;

		if (startA == 'a') {
			m_MainMenuState = MainMenuState::SELECT;
		}
	}
	else {
		char genAlgoNum;
		cin >> genAlgoNum;

		if (genAlgoNum == '1') {
			m_StateManager->setAlgorithm(1);
			m_StateManager->setState(State::MAZE);
		}
		else if (genAlgoNum == '2') {
			m_StateManager->setAlgorithm(2);
			m_StateManager->setState(State::MAZE);
		}
		else if (genAlgoNum == '3') {
			m_StateManager->setAlgorithm(3);
			m_StateManager->setState(State::MAZE);
		}
		else if (genAlgoNum == '4') {
			m_StateManager->setAlgorithm(4);
			m_StateManager->setState(State::MAZE);
		}
	}
}