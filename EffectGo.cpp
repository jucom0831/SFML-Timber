#include "stdafx.h"
#include "EffectGo.h"

EffectGo::EffectGo(const std::string& texId, const std::string& name)
	:GameObject(name), textureId(texId), duration(0), playtime(-1), speed(-1)
{
}

EffectGo::~EffectGo()
{
}

void EffectGo::Reset()
{
	duration = 0;
	playtime = -1;
	speed = -1;
}

void EffectGo::Update(float dt)
{
	playtime += dt;
	EffectPlay(dt);
}

void EffectGo::Effect(const sf::Vector2f& position, float duration, float speed)
{
	SetActive(true);
	SetPosition(position);
	this->duration = duration;
	playtime = 0;
	this->speed = speed;
}
