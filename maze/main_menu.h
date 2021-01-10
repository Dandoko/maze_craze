#ifndef MAIN_MENU_H
#define MAIN_MENU_H

class StateManager;

enum class MainMenuState {
	WELCOME,
	SELECT
};

class MainMenu {
private:
	StateManager* m_StateManager;
	MainMenuState m_MainMenuState;
public:
	MainMenu(StateManager* stateManager);
	MainMenu(const MainMenu&) = delete;
	virtual ~MainMenu();

	void render();
	void update();
};

#endif