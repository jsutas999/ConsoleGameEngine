#include "SceneManager.h"
#include "Logger.h"

SceneManager* SceneManager::singelton;
SceneManager * SceneManager::getInstance()
{
	return singelton;
}

void SceneManager::LoadNextScene(Scene * scene)
{
	levels.push_back(scene);
	scene->Initialize();
}

void SceneManager::LoadPreviesScene()
{
	Scene* t = levels.back();
	delete t;
	levels.pop_back();
}

Scene * SceneManager::getCurrentScene()
{
	return levels.back();
}

SceneManager::SceneManager()
{
	if (singelton == NULL)
	{
		singelton = this;
	}
	
}


SceneManager::~SceneManager()
{
	while (!levels.empty())
	{
		levels.back()->Deconstruct();
		delete levels.back();
		levels.pop_back();
	}
	Logger::getInstance()->AddMsg("ALL SCENES CLEARED");
}
