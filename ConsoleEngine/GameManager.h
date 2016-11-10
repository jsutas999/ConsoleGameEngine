#pragma once
#include <iostream>
#include "InputManager.h"
#include "Renderer.h"
#include "Map.h"
#include "Entity.h"
#include "Logger.h"
#include "SceneManager.h"
class GameManager
{
public:
	void Run();
	GameManager(int width,int height);
	~GameManager();

	static float getTime();
	static float getDeltaTime();
	static void Quit();

private:
	
	InputManager* input;
	Renderer* renderer;
	Logger logger;
	SceneManager* sceneManager;
	
	static bool isRunning;
	static float timepassed;
	static float deltaTime;
	

};

