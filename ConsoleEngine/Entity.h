#pragma once
#include "Vector2.h"
#include "string"
class Entity
{
public:
	Entity()
	{
		name = "RandomName";
		position.x = 0;
		position.y = 0;
	};
	Entity(int x,int y,std::string name)
	{
		position.x = x;
		position.y = y;
		this->name = name;

	}
	Entity(int x, int y)
	{
		position.x = x;
		position.y = y;
		this->name = "RandomName";

	}

	virtual void Update() = 0;
	virtual void Start() = 0;
	virtual void Deconstruct() = 0;

	Vector2 getPosition()
	{
		return position;
	}
	void  setPosition(Vector2 position)
	{
		this->position = position;
	}

	char getSymbol()
	{
		return symbol;
	}
	void setSymbol(char s)
	{
		symbol = s;
	}


 protected:
	std::string name;
	Vector2 position;
	char symbol;

};

