#include <iostream>

#include "timer.h"

using namespace std;

Timer::Timer() {
	resetStartTime();
	m_DeltaTime = chrono::duration<float>(0.0f);
}

Timer::~Timer() {}

float Timer::getDeltaTime() {
	return m_DeltaTime.count();
}

void Timer::resetStartTime() {
	m_StartTime = chrono::system_clock::now();
}

void Timer::updateDeltaTime() {
	m_DeltaTime = chrono::system_clock::now() - m_StartTime;
}