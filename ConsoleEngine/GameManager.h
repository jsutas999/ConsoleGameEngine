#pragma once
#include "InputManager.h"
#include "Renderer.h"
#include "Map.h"
#include "Entity.h"
#include "Logger.h"
#include <iostream>
class GameManager
{
public:
	void Run();
	GameManager(int width,int height);
	~GameManager();

	static float getTime();

private:
	bool isRunning;
	InputManager* input;
	Renderer* renderer;
	Logger logger;
	
	static float timepassed;
	

};

