#include "InputManager.h"


 InputManager* InputManager::singleton;

void InputManager::UpdateLastKeyPress()
{
	for (int i = 8; i <= 256; i++)
	{
		if (GetAsyncKeyState(i) & 0x7FFF)
		{
			lastKeyCode = i;
			return;
		}
	}

	lastKeyCode = 0;
}

int InputManager::getLastKeyCode()
{
	return lastKeyCode;
}



InputManager* InputManager::getInstance()
{
	return singleton;
}

InputManager::InputManager()
{

	if (InputManager::singleton == NULL)
		InputManager::singleton = this;
}


InputManager::~InputManager()
{

}
