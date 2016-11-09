#pragma once
#include "Entity.h"

class PlayerController : public Entity
{
public:
	PlayerController();
	~PlayerController();
	void Update();
	void Start();

private:
	float x;
	float y;
	float r;
	Vector2 startpos;
};

