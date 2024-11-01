#include "stdafx.h"
#include "EffectLog.h"

EffectLog::EffectLog()
	: SpriteGo("graphics/log.png")
{
	TEXTURE_MGR.Load("graphics/log.png");
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
	SetActive(false);
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
	SetActive(true);
	velocity = v;
	timer = 0.f;
}
