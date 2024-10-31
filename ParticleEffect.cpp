#include "stdafx.h"
#include "ParticleEffect.h"

ParticleEffect::ParticleEffect()
	:EffectGo("graphics/dust.png", "")
{
}

ParticleEffect::ParticleEffect(const std::string& texId, const std::string& name)
	:EffectGo(texId, name)
{
}

ParticleEffect::~ParticleEffect()
{
}

void ParticleEffect::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	particle[0].setPosition({ position.x - offset.x * 0.2f, position.y - offset.y * 0.7f });
	particle[1].setPosition({ position.x + offset.x * 0.8f, position.y + offset.y * 0.5f });
	particle[2].setPosition({ position.x + offset.x * 1.2f, position.y - offset.y });
	particle[3].setPosition({ position.x - offset.x, position.y + offset.y * 0.5f });
	particle[4].setPosition({ position.x, position.y - offset.y * 0.8f });
}

void ParticleEffect::SetScale(const sf::Vector2f& scale)
{
	sf::Vector2f prvscale = this->scale;
	this->scale = scale;
	for (auto& sprite : particle)
	{
		sf::Vector2f ps = sprite.getScale();
		sprite.setScale(ps.x * this->scale.x / prvscale.x, ps.y * this->scale.y / prvscale.y);
	}
}

void ParticleEffect::Init()
{
	EffectGo::Init();
}

void ParticleEffect::Reset()
{
	EffectGo::Reset();
	for (auto& sprite : particle)
	{
		sprite.setTexture(TEXTURE_MGR.Get(textureId));
	}

	offset = sf::Vector2f(15, 15);

	particle[0].rotate(60);
	particle[1].rotate(120);
	particle[2].rotate(180);
	particle[3].rotate(210);
	particle[4].rotate(0);

	particle[0].setScale(0.8f, 0.8f);
	particle[1].setScale(1.6f, 1.6f);
	particle[2].setScale(1, 1);
	particle[3].setScale(0.8f, 0.8f);
	particle[4].setScale(1.2f, 1.2f);
}

void ParticleEffect::Draw(sf::RenderWindow& window)
{
	for (auto& sprite : particle)
	{
		window.draw(sprite);
	}
}

bool ParticleEffect::IsSatisfiedCondition()
{
	return playtime > duration;
}

void ParticleEffect::EffectPlay(float dt)
{
	for (auto& sprite : particle)
	{
		sf::Vector2f scale = sprite.getScale();
		scale *= 1 - (dt * speed);
		sprite.setScale(scale);
	}
}
