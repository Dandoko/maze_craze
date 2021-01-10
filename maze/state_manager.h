#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

class Maze;

class StateManager {
private:
	Maze* m_Maze;
public:
	StateManager();
	StateManager(const StateManager&) = delete;
	virtual ~StateManager();

	Maze* getMaze();
};

#endif