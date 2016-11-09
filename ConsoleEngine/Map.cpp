#include "Map.h"



Map::Map(int w,int h)
{
	mapBuffer = new char[w*h];
}


Map::~Map()
{
	delete mapBuffer;
}
