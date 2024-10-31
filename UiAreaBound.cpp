#include "stdafx.h"
#include "UiAreaBound.h"

UiAreaBound::UiAreaBound(const std::string& fontid, const std::string& name)
	: fontid(fontid)
{
	GameObject::sortingLayer = SortingLayers::UI;
}

UiAreaBound::~UiAreaBound()
{
}

void UiAreaBound::Init()
{
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color(255,255,255,150));
	rect.setOutlineThickness(3);
	text.setFont(FONT_MGR.Get(fontid));
	text.setFillColor(sf::Color::White);
}

void UiAreaBound::Reset()
{
	text.setFont(FONT_MGR.Get(fontid));
}

void UiAreaBound::Draw(sf::RenderWindow& window)
{
	window.draw(rect);
	window.draw(text);
}

void UiAreaBound::SetString(const std::string& str, int size)
{
	text.setString(str);
	text.setCharacterSize(size);
	text.setOrigin(0, 0);
	text.setPosition({ rect.getPosition().x, 0 });
}

void UiAreaBound::SetRectangle(const sf::FloatRect& rect)
{
	this->rect.setPosition(rect.left, rect.top);
	this->rect.setSize({ rect.width, rect.height });
	text.setPosition({ rect.getPosition().x, 0});
}
