#include <iostream>

#include "empty_path.h"

using namespace std;

EmptyPath::EmptyPath() : Path(' ') {

}

EmptyPath::~EmptyPath() {}

bool EmptyPath::isEmptyPath() {
	return true;
}