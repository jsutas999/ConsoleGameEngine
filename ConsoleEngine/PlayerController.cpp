#include "PlayerController.h"
#include "InputManager.h"
#include <iostream>
#include <math.h>
#include "GameManager.h"

PlayerController::PlayerController() : Entity()
{
	symbol = 'P';
	r = 5.0;
	startpos = position;

}


PlayerController::~PlayerController()
{
}

void PlayerController::Update()
{
	int b = InputManager::getInstance()->getLastKeyCode();

	if (b == 38) position.y--;
	else if (b == 39) position.x++;
	else if (b == 37) position.x--;
	else if (b == 40) position.y++;

	y = std::sin(startpos.y +   GameManager::getTime())*r;
	x = std::cos(startpos.x +   GameManager::getTime())*r*1.5;
	
	position.x = (int)x;
	position.y = (int)y;
	Logger::getInstance()->AddMsg(std::to_string(x));

	Renderer::getInstance()->AddToDrawQueue('X', 0, 0);


}
 
void PlayerController::Start() 
{

}
