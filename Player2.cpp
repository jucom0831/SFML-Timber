#include "stdafx.h"
#include "Player2.h"
#include "SceneDev3.h"	

Player2::Player2(const std::string& name) : GameObject(name)
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;
}

void Player2::SetSide(Sides s)
{
	side = s;

	if (side == Sides::Left)
	{
		SetScale({ -1.f, 1.f });
	}
	else if (side == Sides::Right)
	{
		SetScale({ 1.f, 1.f });
	}

	sf::Vector2f newPos = position + localPosPlayer[(int)s];
	spritePlayer2.setPosition(newPos);
	spriteAxe.setPosition(newPos + localPosAxe);
	spriteRip.setPosition(newPos + localRipAxe);
}

void Player2::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	SetSide(side);
}

void Player2::OnDie()
{
	isAlive2 = false;
	isChppoing2 = false;


}

void Player2::SetScale(const sf::Vector2f& scale)
{
	this->scale = scale;
	spritePlayer2.setScale(this->scale);

	sf::Vector2f axeScale = this->scale;
	axeScale.x *= -1.f;
	spriteAxe.setScale(axeScale);

	sf::Vector2f axeRip = this->scale;
	axeRip.x = abs(axeScale.x);
	spriteRip.setScale(axeRip);
}

void Player2::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (preset != Origins::Custom)
	{
		origin = Utils::SetOrigin(spritePlayer2, preset);
	}
}

void Player2::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	spritePlayer2.setOrigin(origin);
}

void Player2::Init()
{
	spritePlayer2.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	SetOrigin(Origins::BC);

	spriteAxe.setTexture(TEXTURE_MGR.Get(texIdAxe));
	spriteAxe.setOrigin(originAxe);

	spriteRip.setTexture(TEXTURE_MGR.Get(texIdRip));
	Utils::SetOrigin(spriteRip, Origins::BC);
}

void Player2::Reset()
{
	sfxChop.setBuffer(SOUNDBUFFER_MGR.Get(sbIdChop));

	spritePlayer2.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	spriteAxe.setTexture(TEXTURE_MGR.Get(texIdAxe));
	spriteRip.setTexture(TEXTURE_MGR.Get(texIdRip));

	isAlive2 = true;
	isChppoing2 = false;
	SetPosition(position);
	SetScale({ 1.f, 1.f });
	SetSide(Sides::Right);
}


void Player2::Release()
{
}


void Player2::Update(float dt)
{
	if (!isAlive2)
		return;

	if (InputMgr::GetKeyDown(sf::Keyboard::A))
	{
		isChppoing2 = true;
		SetSide(Sides::Left);
		sceneGame2->OnChop2(Sides::Left);
		sfxChop.play();
	}

	if (InputMgr::GetKeyUp(sf::Keyboard::A))
	{
		isChppoing2 = false;
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::D))
	{
		isChppoing2 = true;
		SetSide(Sides::Right);
		sceneGame2->OnChop2(Sides::Right);
	}

	if (InputMgr::GetKeyUp(sf::Keyboard::D))
	{
		isChppoing2 = false;
		isChppoing2 = false;
	}
}

void Player2::Draw(sf::RenderWindow& window)
{
	if (isAlive2)
	{
		window.draw(spritePlayer2);
		if (isChppoing2)
		{
			window.draw(spriteAxe);
		}
	}
	else
	{
		window.draw(spriteRip);
	}
}

void Player2::SetSceneGame2(SceneDev3* scene)
{
	sceneGame2 = scene;
}
