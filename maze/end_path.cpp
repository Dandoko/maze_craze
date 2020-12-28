#include <iostream>

#include "end_path.h"

using namespace std;

EndPath::EndPath(char shape) : NonEmptyPath(shape, 0) {

}

EndPath::~EndPath() {}

bool EndPath::isEndPath() {
	return true;
}