#include <iostream>

#include "manager.h"

using namespace std;

int main() {
	Manager* manager = Manager::getManagerInstance();
	manager->start();
	Manager::destoryManagerInstance();
	return 0;
}