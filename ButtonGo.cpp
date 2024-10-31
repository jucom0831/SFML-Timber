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
	sf::Vector2f Mousepos = (sf::Vector2f)(sf::Mouse::getPosition(FRAMEWORK.GetWindow()));
	if(sprite.getGlobalBounds().contains(Mousepos) && InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	{
		std::cout << "Mouse Left click" << std::endl;
		isclicked = true;
	}
}

void ButtonGo::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
