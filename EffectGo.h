#pragma once
#include "GameObject.h"
#include "ObjectPoolable.h"
class EffectGo :
	public GameObject, ObjectPoolable
{
protected:
	EffectGo(const std::string& texId, const std::string& name);
public:
	~EffectGo();
	//void SetPosition(const sf::Vector2f& pos) override;
	//void SetScale(const sf::Vector2f& scale) override;
	//void SetOrigin(Origins preset) override;
	//void SetOrigin(const sf::Vector2f& newOrigin)override;

	//void Init();
	//void Release();
	void Reset();
	void Update(float dt);
	//void Draw(sf::RenderWindow& window);

	void Effect(const sf::Vector2f& position, float duration, float speed);
protected:
	virtual void EffectPlay(float dt)=0;

	std::string textureId;
	float duration = 0;
	float playtime =-1;
	float speed = -1;
};

