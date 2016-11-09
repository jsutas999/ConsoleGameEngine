#include "GameManager.h"
#include "PlayerController.h"
#include <list>
#include <time.h> 
#include <thread>
#include <chrono> 
void GameManager::Run()
{
	isRunning = true;

	std::list<Entity*> gameObjects;
	gameObjects.push_back(new PlayerController());
	float timePerFrame = 1/60;
	clock_t t;
	t = clock();
	clock_t start = clock();

	float fl = timePerFrame;

	int i;

	while (isRunning)
	{
		t = clock() - t;
		timepassed = ((float)clock() - start ) / CLOCKS_PER_SEC;
		fl -= float(t) / CLOCKS_PER_SEC;

		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		t = clock();
		if(fl > 0.0)
		{
			continue;
		}
		
		fl = timePerFrame;
		
		//Clear screen
		renderer->ClearScreen();
		// Get the newest input
		input->UpdateLastKeyPress();

		//Update states and prepare draw buffer
		for (std::list<Entity*>::iterator it = gameObjects.begin(); it != gameObjects.end(); it++)
		{
			(*it)->Update();
			renderer->AddToDrawQueue( *it );
		}
		// Draw Screen
		renderer->Draw();
		// Draw Messages
		logger.PrintMsg();

		std:: cout << timepassed;
		
		//std::cin >> i;
	}
}

GameManager::GameManager(int width,int height)
{
	isRunning = false;
	this->input = new InputManager();
	this->renderer = new Renderer(width,height);
}


GameManager::~GameManager()
{
	delete input;
	delete renderer;
}

float GameManager::timepassed;

float GameManager::getTime()
{
	return timepassed;
}
