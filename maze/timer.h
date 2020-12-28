#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
private:
	std::chrono::system_clock::time_point m_startTime;
	std::chrono::duration<float> m_deltaTime;

public:
	Timer();
	Timer(const Timer&) = delete;
	~Timer();

	void resetStartTime();

	float getDeltaTime();
	void updateDeltaTime();
};

#endif