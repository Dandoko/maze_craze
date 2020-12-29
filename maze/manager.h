#ifndef MANAGER_H
#define MANAGER_H

class Loop;
class Maze;

class Manager {
private:
	static Manager* sManagerInstance;
	Maze* m_Maze;
	Loop* m_Loop;

	Manager();
	Manager(const Manager&) = delete;
	virtual ~Manager();

public:
	static Manager* getManagerInstance();
	static void destoryManagerInstance();

	void start();

	void update();
	void render();
};

#endif