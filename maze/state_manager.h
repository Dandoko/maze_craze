#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

enum State;
class Maze;
class MainMenu;

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