#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
private:
	std::chrono::system_clock::time_point m_StartTime;
	std::chrono::duration<float> m_DeltaTime;

public:
	Timer();
	Timer(const Timer&) = delete;
	virtual ~Timer();

	float getDeltaTime();

	void resetStartTime();
	void updateDeltaTime();
};

#endif