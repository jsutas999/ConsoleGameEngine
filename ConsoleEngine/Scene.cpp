#include "Scene.h"
#include "Logger.h"
#include "Renderer.h"

Scene::Scene()
{
}


Scene::~Scene()
{
	while (!gameObjects.empty())
	{
		gameObjects.front()->Deconstruct();
		delete gameObjects.front();
		gameObjects.pop_front();
	}

	Logger::getInstance()->AddMsg("Destroyed Scene! Obj: " + gameObjects.size());
}

void Scene::Update()
{
	for (std::list<Entity*>::iterator it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		(*it)->Update();
		Renderer::getInstance()->AddToDrawQueue(*it);
	}

}
