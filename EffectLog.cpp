#include "stdafx.h"
#include "EffectLog.h"

EffectLog::EffectLog()
	: SpriteGo("graphics/log.png")
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 1;
}

EffectLog::EffectLog(const std::string& texId, const std::string& name)
	: SpriteGo(texId, name)
{
}

bool EffectLog::IsSatisfiedCondition()
{
	return timer > duration;
}

void EffectLog::Reset()
{
	SpriteGo::Reset();
	timer = 0;
}

void EffectLog::Update(float dt)
{
	timer += dt;
	velocity += gravity * dt;
	SetPosition(position + velocity * dt);
}

void EffectLog::Fire(sf::Vector2f v)
{
	velocity = v;
	timer = 0.f;
}
