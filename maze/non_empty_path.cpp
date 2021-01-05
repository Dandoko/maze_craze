#include <iostream>

#include "non_empty_path.h"

using namespace std;

NonEmptyPath::NonEmptyPath(char shape, int color) : Path(shape) {
}

NonEmptyPath::~NonEmptyPath() {}

bool NonEmptyPath::isNonEmptyPath() {
	return true;
}

bool NonEmptyPath::isStartPath() {
	return false;
}

bool NonEmptyPath::isEndPath() {
	return false;
}