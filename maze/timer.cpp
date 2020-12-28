#include <iostream>

#include "timer.h"

using namespace std;

Timer::Timer() {
	resetStartTime();
	m_deltaTime = chrono::duration<float>(0.0f);
}

Timer::~Timer() {}

void Timer::resetStartTime() {
	m_startTime = chrono::system_clock::now();
}

float Timer::getDeltaTime() {
	return m_deltaTime.count();
}

void Timer::updateDeltaTime() {
	m_deltaTime = chrono::system_clock::now() - m_startTime;
}