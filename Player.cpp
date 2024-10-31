#include "stdafx.h"
#include "Player.h"
#include "SceneDev1.h"	
#include "SceneDev3.h"	

Player::Player(const std::string& name) : GameObject(name)
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;
}

void Player::SetSide(Sides s)
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
	spritePlayer.setPosition(newPos);
	spriteAxe.setPosition(newPos + localPosAxe);
	spriteRip.setPosition(newPos + localRipAxe);
}

void Player::SetSprite(std::string textureid)
{
	texIdPlayer = textureid;
	spritePlayer.setTexture(TEXTURE_MGR.Get(textureid));
	SetOrigin(Origins::BC);
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	SetSide(side);
}

void Player::OnDie()
{
	isAlive = false;
	isChppoing = false;
}

void Player::SetScale(const sf::Vector2f& scale)
{
	this->scale = scale;
	spritePlayer.setScale(this->scale);

	sf::Vector2f axeScale = this->scale;
	axeScale.x *= -1.f;
	spriteAxe.setScale(axeScale);

	sf::Vector2f axeRip = this->scale;
	axeRip.x = abs(axeScale.x);
	spriteRip.setScale(axeRip);
}

void Player::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (preset != Origins::Custom)
	{
		origin = Utils::SetOrigin(spritePlayer, preset);
		
	}
}
void Player::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	spritePlayer.setOrigin(origin);

}


void Player::Init()
{

	spriteAxe.setTexture(TEXTURE_MGR.Get(texIdAxe));
	spriteAxe.setOrigin(originAxe);

	spriteRip.setTexture(TEXTURE_MGR.Get(texIdRip));
	Utils::SetOrigin(spriteRip, Origins::BC);
}

void Player::Reset()
{
	sfxChop.setBuffer(SOUNDBUFFER_MGR.Get(sbIdChop));


	spriteAxe.setTexture(TEXTURE_MGR.Get(texIdAxe));
	spriteRip.setTexture(TEXTURE_MGR.Get(texIdRip));

	isAlive = true;
	isChppoing = false;
	isChppoing2 = false;
	SetPosition(position);
	SetScale({ 1.f, 1.f });
	SetSide(Sides::Right);
}


void Player::Release()
{
}


void Player::Update(float dt)
{
	if (!isAlive)
		return;
	if (texIdPlayer == "graphics/player.png") {
		if (InputMgr::GetKeyDown(sf::Keyboard::Left))
		{
			isChppoing = true;
			SetSide(Sides::Left);
			dynamic_cast<SceneDev3*>(sceneGame)->OnChop(Sides::Left);
			sfxChop.play();
		}

		if (InputMgr::GetKeyUp(sf::Keyboard::Left))
		{
			isChppoing = false;
		}

		if (InputMgr::GetKeyDown(sf::Keyboard::Right))
		{
			isChppoing = true;
			SetSide(Sides::Right);
			dynamic_cast<SceneDev3*>(sceneGame)->OnChop(Sides::Right);
		}

		if (InputMgr::GetKeyUp(sf::Keyboard::Right))
		{
			isChppoing = false;
		}
	}
	if (texIdPlayer == "graphics/player2.png") {
		if (InputMgr::GetKeyDown(sf::Keyboard::A))
		{
			isChppoing2 = true;
			SetSide(Sides::Left);
			dynamic_cast<SceneDev3*>(sceneGame)->OnChop2(Sides::Left);
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
			dynamic_cast<SceneDev3*>(sceneGame)->OnChop2(Sides::Right);
		}

		if (InputMgr::GetKeyUp(sf::Keyboard::D))
		{
			isChppoing2 = false;
		}
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	if (isAlive)
	{
		window.draw(spritePlayer);
		if (isChppoing)
		{
			window.draw(spriteAxe);
		}
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

void Player::SetSceneGame(Scene* scene)
{
	sceneGame = scene;
}