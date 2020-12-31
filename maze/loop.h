#ifndef LOOP_H
#define LOOP_H

class Timer;
class Manager;

#define MAX_FRAME_RATE 1.0f/2.0f

class Loop {
private:
	Timer* m_Timer;
	Manager* m_Manager;
	bool m_IsRunning;

	void run();

public:
	Loop(Manager* manager);
	Loop(const Loop&) = delete;
	virtual ~Loop();

	void start();
};

#endif