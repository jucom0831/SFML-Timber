#pragma once
#include "EffectGo.h"
class ParticleEffect :
    public EffectGo
{
public:
	ParticleEffect();
	ParticleEffect(const std::string& texId, const std::string& name="");
	~ParticleEffect();

	void SetPosition(const sf::Vector2f& pos) override;
	void SetScale(const sf::Vector2f& scale) override;

	void Init();
	void Reset();
	void Draw(sf::RenderWindow& window);

	bool IsSatisfiedCondition();
protected:
	void EffectPlay(float dt);

	sf::Sprite particle[5];
	sf::Vector2f offset;
};

