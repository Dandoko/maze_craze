#include <iostream>

#include "start_path.h"

using namespace std;

StartPath::StartPath(char shape) : NonEmptyPath(shape, 0) {
	
}

StartPath::~StartPath() {}

bool StartPath::isStartPath() {
	return true;
}