#include <iostream>

#include "creator.h"

using namespace std;

Creator::Creator() : Unit('C') {

}

Creator::~Creator() {}

bool Creator::isCreator() {
	return true;
}