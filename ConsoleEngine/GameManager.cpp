#include "GameManager.h"
#include "PlayerController.h"
#include "InitScene.h"
#include <list>
#include <time.h> 
#include <thread>
#include <chrono> 
void GameManager::Run()
{
	isRunning = true;
	
	float timePerFrame = 1/60;
	
	clock_t t;
	
	t = clock();

	clock_t start = clock();

	float fl = timePerFrame;

	//Bootstrap the scene
	sceneManager->LoadNextScene(new InitScene());

	while (isRunning)
	{
		
		// Menage Time
		t = clock() - t;
		timepassed = ((float)clock() - start ) / CLOCKS_PER_SEC;
		fl -= float(t) / CLOCKS_PER_SEC;
		deltaTime = fl;

		std::this_thread::sleep_for(std::chrono::milliseconds(200));

		t = clock();

		if(fl > 0.0)
		{
			continue;
		}
		
		fl = timePerFrame;

		// Clear Screen
		renderer->ClearScreen();
		// Update Input
		input->UpdateLastKeyPress();
		//Update all gameobjects in the scene
		sceneManager->getCurrentScene()->Update();
		// Draw The Screen
		renderer->Draw();
		//Print Logger messages
		logger.PrintMsg();
		
	}

}

GameManager::GameManager(int width,int height)
{
	isRunning = false;
	this->input = new InputManager();
	this->renderer = new Renderer(width,height);
	this->sceneManager = new SceneManager();
}


GameManager::~GameManager()
{
	delete input;
	delete renderer;
	delete sceneManager;
}

float GameManager::timepassed;
float GameManager::getTime()
{
	return timepassed;
}
float GameManager::deltaTime;
float GameManager::getDeltaTime()
{
	return deltaTime;
}

bool GameManager::isRunning;
void GameManager::Quit()
{
	isRunning = false;
}
