#include <iostream>

#include "creator.h"

using namespace std;

Creator::Creator(char shape) : Unit(shape) {

}

Creator::~Creator() {}

bool Creator::isCreator() {
	return true;
}