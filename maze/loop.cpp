#include <iostream>
#include <windows.h>
#include <thread>

#include "loop.h"
#include "timer.h"
#include "manager.h"

using namespace std;

Loop::Loop(Manager* manager) {
	m_Timer = new Timer();
	m_Manager = manager;
	m_IsRunning = false;
}

Loop::~Loop() {
	delete m_Timer;
	m_Timer = NULL;
}

void Loop::start() {
	run();
}

void Loop::run() {
	m_IsRunning = true;

	m_Timer->resetStartTime();
	float elaspedTime = 0.0f;
	bool render = false;

	float frameTime = 0;
	int frames = 0;
	int fps = 0;

	while (m_IsRunning) {
		render = false;

		m_Timer->updateDeltaTime();
		m_Timer->resetStartTime();
		elaspedTime += m_Timer->getDeltaTime();
		frameTime += m_Timer->getDeltaTime();

		while (elaspedTime >= MAX_FRAME_RATE) {
			elaspedTime -= MAX_FRAME_RATE;
			render = true;

			// Update game
			m_Manager->update();

			if (frameTime >= 1.0f) {
				frameTime = 0;
				fps = frames;
				frames = 0;
				//cout << "FPS: " << fps << endl;
			}
		}

		if (render) {
			frames++;

			COORD cursorPosition;
			cursorPosition.X = 0;
			cursorPosition.Y = 0;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
			
			m_Manager->render();
		}
		else {
			this_thread::sleep_for(1ms);
		}
	}
}