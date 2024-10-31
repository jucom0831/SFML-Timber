#pragma once
#include "SpriteGo.h"
class EffectLog2 : public SpriteGo
{
protected:
	sf::Vector2f gravity = { 0.f, 1000.f };
	sf::Vector2f velocity;

	float duration = 3.f;
	float timer = 0.f;

public:
	EffectLog2();
	EffectLog2(const std::string& texId, const std::string& name = "");
	~EffectLog2() = default;

	void Update(float dt) override;

	void Fire(sf::Vector2f v);
};
