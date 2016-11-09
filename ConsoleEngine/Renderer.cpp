#include "Renderer.h"


Renderer* Renderer::singleton;

Renderer* Renderer::getInstance()
{
	 return singleton;
}

Renderer::Renderer(int width, int height)
{

	if (Renderer::singleton == NULL)
		singleton = this;

	
	camPos.x = 0;
	camPos.y = 0;

	buffer = new char[width*height];

	for (int i = 0; i < width*height;i++)
		buffer[i] =  '!';


	w = width;
	h = height;

}


Renderer::~Renderer()
{
	delete buffer;
}

void Renderer::AddToDrawQueue(char symbol,int mapX, int mapY)
{
	Vector2 w2c = WorldSpaceToScreenSpace(mapX, mapY);

	

	if (w2c.x > -w / 2 && w2c.y > -h / 2)
	{
		if (w2c.x < w / 2 && w2c.y < h / 2)
		{
			w2c.x += w / 2;
			w2c.y += h / 2;


			buffer[w2c.y*w + w2c.x] = symbol;
		}
	}
}

void Renderer::AddToDrawQueue(Entity* en)
{
	Renderer::AddToDrawQueue(en->getSymbol(), en->getPosition().x, en->getPosition().y);
}



void Renderer::Draw()
{
	std::string t = buffer;
	for (int i = 1; i < h; i++)
	{
		t.insert(i*w+i-1, "\n");
	}

	std::ostream stream(nullptr);
	stream.rdbuf(std::cout.rdbuf());
	stream << t;
	
	//t.erase(t.size() - 10, t.size()); // Kazkodel atsiranda 10 siukslinu simboliu todel juos istrinam
	//std::cout << t;
}

void Renderer::MoveCam(int x, int y)
{
	camPos.x = x;
	camPos.y = y;
}

void Renderer::TranslateCam(int x, int y)
{
	MoveCam(camPos.x + x, camPos.y + y);
}

Vector2 Renderer::WorldSpaceToScreenSpace(int  x, int  y)
{
	Vector2 screenspace;
	screenspace.x = x - camPos.x;
	screenspace.y = y - camPos.y;
	return screenspace;
}

void Renderer::ClearScreen()
{
	system("cls");
	for (int i = 0; i < w*h; i++)
		buffer[i] = ' ';
}
