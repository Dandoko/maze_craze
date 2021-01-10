#ifndef MANAGER_H
#define MANAGER_H

class Loop;
class Maze;
class KeyboardInput;
class Renderer;
class StateManager;

class Manager {
private:
	static Manager* sManagerInstance;
	KeyboardInput* m_KeyboardInput;
	StateManager* m_StateManager;
	Renderer* m_Renderer;
	Loop* m_Loop;

	Manager();
	Manager(const Manager&) = delete;
	virtual ~Manager();

public:
	static Manager* getManagerInstance();
	static void destoryManagerInstance();

	StateManager* getStateManager();

	void start();
	void update();
	void render();
};

#endif