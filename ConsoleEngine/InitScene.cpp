#include "InitScene.h"
#include "PlayerController.h"
#include "Logger.h"

InitScene::InitScene()
{
}

void InitScene::Deconstruct()
{
	
}

void InitScene::Initialize()
{
	gameObjects.push_back(new PlayerController());

}
