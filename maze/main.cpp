#include <iostream>

#include "manager.h"

int main() {
	Manager* manager = Manager::getManagerInstance();

	manager->start();

	Manager::destoryManagerInstance();
	return 0;
}