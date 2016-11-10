#pragma once
#include "Entity.h"

class PlayerController : public Entity
{
public:
	PlayerController();
	void Update();
	void Start();
	// This method should handle the deconstruction of the object
	void Deconstruct();

private:
	float x;
	float y;
	float r;
	Vector2 startpos;
};

