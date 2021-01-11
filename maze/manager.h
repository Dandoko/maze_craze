#ifndef MANAGER_H
#define MANAGER_H

class Loop;
class Maze;
class KeyboardInput;
class StateManager;

class Manager {
private:
	static Manager* sManagerInstance;
	KeyboardInput* m_KeyboardInput;
	StateManager* m_StateManager;
	Loop* m_Loop;

	Manager();
	Manager(const Manager&) = delete;
	virtual ~Manager();

public:
	static Manager* getManagerInstance();
	static void destoryManagerInstance();

	KeyboardInput* getKeyboardInput();
	StateManager* getStateManager();

	void start();
	void update();
	void render();

	bool inMainMenu();
};

#endif