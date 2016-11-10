#pragma once
#include <list>
#include "Entity.h"
class Scene
{
public:
	 Scene();
	~Scene();
	void Update();
	// Is called after the creation of the scene
	virtual void Initialize() = 0;

	// Is called before the ~Scene.
	// This should handle all of the memory that has to be freed exept for gameObjects 
	virtual void Deconstruct() = 0;
protected:
	std::list<Entity*> gameObjects;
};

