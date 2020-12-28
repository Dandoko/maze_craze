#ifndef MANAGER_H
#define MANAGER_H

#include "loop.h"
#include "maze.h"

class Manager {
private:
	static Manager* sManagerInstance;
	Maze* m_Maze;
	Loop* m_Loop;

	Manager();
	Manager(const Manager&) = delete;
	~Manager();

public:
	static Manager* getManagerInstance();
	static void destoryManagerInstance();

	void start();
};

#endif