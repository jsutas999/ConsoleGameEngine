#pragma once
#include "Vector2.h"
#include "string"
//The base class that every gameObject derives from
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
	// This method is called at the start of a each frame
	virtual void Update() = 0;
	// This method is called only once after the creation of the object
	virtual void Start() = 0;
	// Is called before freeing up the Entity memory
	virtual void Deconstruct() = 0;

	// Return the position of the Entity
	Vector2 getPosition()
	{
		return position;
	}
	// Sets position of the Entity
	void  setPosition(Vector2 position)
	{
		this->position = position;
	}
	// Get current symbol representing Entity in rendering 
	char getSymbol()
	{
		return symbol;
	}
	// Sets symobol representing the Entity in rendering
	void setSymbol(char s)
	{
		symbol = s;
	}


 protected:
	std::string name;
	Vector2 position;
	char symbol;

};

