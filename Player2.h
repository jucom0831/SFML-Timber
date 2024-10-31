#pragma once
#include "GameObject.h"

class SceneDev3;

class Player2 : public GameObject
{
protected:
	sf::Sound sfxChop;


	sf::Sprite spritePlayer2;
	sf::Sprite spriteAxe;
	sf::Sprite spriteRip;

	std::string sbIdChop = "sound/chop.wav";
	std::string texIdPlayer = "graphics/player2.png";
	std::string texIdAxe = "graphics/axe.png";
	std::string texIdRip = "graphics/rip.png";

	Sides side = Sides::Right;

	sf::Vector2f localPosPlayer[3] = { { -300.f, 0.f },  { 300.f, 0.f },  { 0.f, 0.f } };
	sf::Vector2f localPosAxe = { 0.f, -70.f };
	sf::Vector2f localRipAxe = { 0.f, 0.f };

	sf::Vector2f originAxe = { -65.f, 0.f };

	bool isAlive2 = true;
	bool isChppoing2 = false;

	SceneDev3* sceneGame2 = nullptr;

public:
	Player2(const std::string& name = "");
	virtual ~Player2() = default;

	Sides GetSide() const { return side; }
	void SetSide(Sides s);
	void OnDie();

	void SetPosition(const sf::Vector2f& pos) override;
	void SetScale(const sf::Vector2f& scale) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Init() override;
	void Release() override;
	void Reset()  override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window)  override;

	void SetSceneGame2(SceneDev3* scene);
};

