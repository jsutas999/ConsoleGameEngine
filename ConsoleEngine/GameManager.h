#pragma once
#include <iostream>
#include "InputManager.h"
#include "Renderer.h"
#include "Map.h"
#include "Entity.h"
#include "Logger.h"
#include "SceneManager.h"
//Handles Input,logging and rendering 
//There should only be one istance of it per program
class GameManager
{
public:
	//Starts to execute the main loop of the game
	void Run();
	//Wwidth and height of the display
	GameManager(int width,int height);
	~GameManager();

	// Time from start of the program
	// Time is returned in secods
	static float getTime();

	// Time from the last frame in seconds
	static float getDeltaTime();
	
	//Exits the main loop
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

