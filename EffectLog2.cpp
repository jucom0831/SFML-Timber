#include "stdafx.h"
#include "EffectLog2.h"

EffectLog2::EffectLog2()
	: SpriteGo("graphics/log.png")
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 1;
}

EffectLog2::EffectLog2(const std::string& texId, const std::string& name)
	: SpriteGo(texId, name)
{
}

void EffectLog2::Update(float dt)
{
	timer += dt;
	if (timer > duration)
	{
		SetActive(false);
		return;
	}

	velocity += gravity * dt;
	SetPosition(position + velocity * dt);
}

void EffectLog2::Fire(sf::Vector2f v)
{
	velocity = v;
	timer = 0.f;
}
