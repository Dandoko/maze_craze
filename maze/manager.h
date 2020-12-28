#ifndef MANAGER_H
#define MANAGER_H

#include "loop.h"

class Manager {
private:
	static Manager* sManagerInstance;
	Loop* loop;

	Manager();
	Manager(const Manager&) = delete;
	~Manager();

public:
	static Manager* getManagerInstance();
	static void destoryManagerInstance();

	void start();
};

#endif