#pragma once
#include <string>
#include <iostream>
#include "Vector2.h"
#include "Entity.h"
class Renderer
{
public:
	static Renderer* getInstance();
	Renderer(int width,int height);
	~Renderer();
	void AddToDrawQueue(char symbol, int mapX, int mapY);
	void AddToDrawQueue(Entity* en);
	void Draw();
	void ClearScreen();
	void MoveCam(int x,int y);
	void TranslateCam(int x,int y);

private:
	int w;
	int h;
	char* buffer;
	Vector2 WorldSpaceToScreenSpace(int x, int y);
	Vector2 camPos;
	static Renderer* singleton;


};

