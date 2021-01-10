#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

class Maze;
class MainMenu;
class Manager;

enum class State {
	MAIN_MENU,
	MAZE
};

class StateManager {
private:
	Manager* m_Manager;
	State m_State;
	Maze* m_Maze;
	MainMenu* m_MainMenu;
public:
	StateManager(Manager* manager);
	StateManager(const StateManager&) = delete;
	virtual ~StateManager();

	Manager* getManager();
	State getState();
	void setState(State state);
	Maze* getMaze();
	MainMenu* getMainMenu();

	void update();
};

#endif