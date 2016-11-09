#pragma once
#include "Windows.h"
class InputManager
{
public:
	static InputManager* getInstance();
	void UpdateLastKeyPress();
	int getLastKeyCode();
	InputManager();
	~InputManager();
private: 
	static InputManager* singleton;
	int lastKeyCode;
};

