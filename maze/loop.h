#ifndef LOOP_H
#define LOOP_H

#include "timer.h"
#include "maze.h"

#define MAX_FRAME_RATE 1.0f/60.0f

class Loop {
private:
	Timer* m_Timer;
	Maze* m_Maze;
	bool m_IsRunning;

	void run();

public:
	Loop(Maze* maze);
	Loop(const Loop&) = delete;
	virtual ~Loop();

	void start();
};

#endif