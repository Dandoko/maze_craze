#include <iostream>

#include "manager.h"

using namespace std;

Manager* Manager::sManagerInstance = NULL;

Manager::Manager() {
	loop = new Loop();
}

Manager::~Manager() {}

Manager* Manager::getManagerInstance() {
	if (!sManagerInstance) sManagerInstance = new Manager();

	return sManagerInstance;
}

void Manager::destoryManagerInstance() {
	delete sManagerInstance;
	sManagerInstance = NULL;
}

void Manager::start() {
	loop->start();
}
