#pragma once
#include <string>
#include <iostream>
#include "Vector2.h"
#include "Entity.h"
// Renders to the console
class Renderer
{
public:
	// Returns instance of it self
	static Renderer* getInstance();
	// width and height of the screen
	Renderer(int width,int height);
	~Renderer();
	// Adds symbol to be drawed later
	void AddToDrawQueue(char symbol, int mapX, int mapY);
	// Adds symbol to be drawed later
	void AddToDrawQueue(Entity* en);
	// Draws the buffer
	void Draw();
	// Clears the screen
	void ClearScreen();
	// Moves camera to the new position
	void MoveCam(int x,int y);
	// Moves Camera reletive to its the last position
	void TranslateCam(int x,int y);

private:
	int w;
	int h;
	char* buffer;
	// Transforms coordinates from world space to screen space
	Vector2 WorldSpaceToScreenSpace(int x, int y);
	Vector2 camPos;
	static Renderer* singleton;


};

