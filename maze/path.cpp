#include <iostream>

#include "path.h"

using namespace std;

Path::Path(char shape) : Cell(shape) {

}

Path::~Path() {}

bool Path::isPath() {
	return true;
}

bool Path::isEmptyPath() {
	return false;
}

bool Path::isNonEmptyPath() {
	return false;
}