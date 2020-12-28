#include <iostream>
#include <windows.h>
#include <thread>

#include "loop.h"

using namespace std;

Loop::Loop() {
	timer = new Timer();
	isRunning = false;
}

Loop::~Loop() {
	delete timer;
}

void Loop::start() {
	run();
}

void Loop::run() {
	isRunning = true;

	timer->resetStartTime();
	float elaspedTime = 0.0f;
	bool render = false;

	float frameTime = 0;
	int frames = 0;
	int fps = 0;

	while (isRunning) {
		render = false;

		timer->updateDeltaTime();
		timer->resetStartTime();
		elaspedTime += timer->getDeltaTime();
		frameTime += timer->getDeltaTime();

		while (elaspedTime >= MAX_FRAME_RATE) {
			elaspedTime -= MAX_FRAME_RATE;
			render = true;

			// Update game

			if (frameTime >= 1.0f) {
				frameTime = 0;
				fps = frames;
				frames = 0;
				cout << "FPS: " << fps << endl;
			}

		}

		if (render) {
			frames++;

			COORD cursorPosition;
			cursorPosition.X = 0;
			cursorPosition.Y = 0;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

			// Render Maze

			for (int i = 0; i < 15; i++) {
				for (int j = 0; j < 15; j++) {
					cout << "X";
				}
				cout << endl;
			}
		}
		else {
			this_thread::sleep_for(1ms);
		}
	}
}