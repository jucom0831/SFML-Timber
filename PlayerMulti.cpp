#include "stdafx.h"
#include "PlayerMulti.h"
#include "SceneGame.h"	

PlayerMulti::PlayerMulti(int number, const std::string& name) : GameObject(name)
,number(number)
{
	sortingLayer = SortingLayers::Foreground;
	sortingOrder = 0;
}

void PlayerMulti::SetSide(Sides s)
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

void PlayerMulti::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	SetSide(side);
}

void PlayerMulti::OnDie()
{
	isAlive = false;
	isChppoing = false;
}

void PlayerMulti::SetScale(const sf::Vector2f& scale)
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

void PlayerMulti::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (preset != Origins::Custom)
	{
		origin = Utils::SetOrigin(spritePlayer, preset);
	}
}

void PlayerMulti::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	spritePlayer.setOrigin(origin);
}

void PlayerMulti::Init()
{
	spritePlayer.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	SetOrigin(Origins::BC);

	spriteAxe.setTexture(TEXTURE_MGR.Get(texIdAxe));
	spriteAxe.setOrigin(originAxe);

	spriteRip.setTexture(TEXTURE_MGR.Get(texIdRip));
	Utils::SetOrigin(spriteRip, Origins::BC);

}

void PlayerMulti::Reset()
{
	sfxChop.setBuffer(SOUNDBUFFER_MGR.Get(sbIdChop));

	spritePlayer.setTexture(TEXTURE_MGR.Get(texIdPlayer));
	spriteAxe.setTexture(TEXTURE_MGR.Get(texIdAxe));
	spriteRip.setTexture(TEXTURE_MGR.Get(texIdRip));

	isAlive = true;
	isChppoing = false;
	SetPosition(position);
	SetScale({ 1.f, 1.f });
	SetSide(Sides::Right);
}


void PlayerMulti::Release()
{
}


void PlayerMulti::Update(float dt)
{
	if (!isAlive)
		return;

	if (InputMgr::GetKeyDown(leftKey))
	{
		isChppoing = true;
		SetSide(Sides::Left);
		sceneGame->OnChop(Sides::Left, number);
		sfxChop.play();
	}

	if (InputMgr::GetKeyUp(leftKey))
	{
		isChppoing = false;
	}

	if (InputMgr::GetKeyDown(rightKey))
	{
		isChppoing = true;
		SetSide(Sides::Right);
		sceneGame->OnChop(Sides::Right, number);
	}

	if (InputMgr::GetKeyUp(rightKey))
	{
		isChppoing = false;
	}
}

void PlayerMulti::Draw(sf::RenderWindow& window)
{
	if (isAlive)
	{
		window.draw(spritePlayer);
		if (isChppoing)
		{
			window.draw(spriteAxe);
		}
	}
	else
	{
		window.draw(spriteRip);
	}
}

void PlayerMulti::SetSceneGame(SceneGame* scene)
{
	sceneGame = scene;
}

void PlayerMulti::SetKeyBoard(sf::Keyboard::Key left, sf::Keyboard::Key right)
{
	leftKey = left;
	rightKey = right;
}
