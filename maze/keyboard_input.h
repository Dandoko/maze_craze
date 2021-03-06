#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

class KeyboardInput {
private:
	bool m_SpacebarClicked;
public:
	KeyboardInput();
	KeyboardInput(const KeyboardInput&) = delete;
	virtual ~KeyboardInput();

	bool getSpacebarClicked();

	void update();
};

#endif