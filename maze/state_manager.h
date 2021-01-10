#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

class Maze;
class MainMenu;

enum class State {
	MAIN_MENU,
	GENERATE,
	SOLVE
};

class StateManager {
private:
	State m_State;
	Maze* m_Maze;
	MainMenu* m_MainMenu;
public:
	StateManager();
	StateManager(const StateManager&) = delete;
	virtual ~StateManager();

	Maze* getMaze();

	void update();
};

#endif