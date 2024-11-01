#include "stdafx.h"
#include "ButtonGo.h"

bool ButtonGo::getisclicked() const
{
	return isclicked;
}

ButtonGo::ButtonGo(const std::string& texId, const std::string& name)
	: SpriteGo(texId, name)
{
	
}


void ButtonGo::Reset() 
{
	SpriteGo::Reset();
	isclicked = false;
}

void ButtonGo::Update(float dt)
{

	sf::Vector2f Mousepos = InputMgr::GetGlobalMousePosition();
	if(sprite.getGlobalBounds().contains(Mousepos) && InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	{
		isclicked = true;
	}
	std::cout << Mousepos.x << std::endl;

}

void ButtonGo::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
