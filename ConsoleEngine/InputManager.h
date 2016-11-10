#pragma once
#include "Windows.h"
class InputManager
{
public:
	// Returns instance of the InputManager
	static InputManager* getInstance();
	// Scans the keybord for the latest keypresses
	void UpdateLastKeyPress();
	// Returns the latest key press 
	int getLastKeyCode();
	InputManager();
	~InputManager();
private: 
	static InputManager* singleton;
	int lastKeyCode;
};

