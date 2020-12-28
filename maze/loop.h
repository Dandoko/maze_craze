#ifndef LOOP_H
#define LOOP_H

#include "timer.h"

#define MAX_FRAME_RATE 1.0f/60.0f

class Loop {
private:
	Timer* timer;
	bool isRunning;

	void run();

public:
	Loop();
	Loop(const Loop&) = delete;
	~Loop();

	void start();
};

#endif