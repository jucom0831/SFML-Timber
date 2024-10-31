#include "stdafx.h"
#include "SceneSelect.h"
#include "SpriteGo.h"
#include "ButtonGo.h"
#include "SceneMgr.h"
#include "Player.h"


SceneSelect::SceneSelect() : Scene(SceneIds::Select)
{
}

void SceneSelect::Init()
{
	std::cout << "SceneSelect::Init()" << std::endl;

	GameObject* obj = AddGo(new SpriteGo("graphics/background.png"));
	Player1 = AddGo(new ButtonGo("graphics/player.png"));
	Player2 = AddGo(new ButtonGo("graphics/player2.png"));
	back = AddGo(new ButtonGo("graphics/back.png"));
	obj->sortingLayer = SortingLayers::Background;
	obj->sortingOrder = -1;
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });
	Player1->SetOrigin(Origins::MC);
	Player1->SetPosition ({ 960 / 2 , 1280 / 2 });
	Player2->SetOrigin(Origins::MC);
	Player2->SetPosition({ 2500 / 2 , 1280 / 2 });
	back->SetOrigin(Origins::TL);
	back->SetPosition({ 0,0 });
	Scene::Init();
}

void SceneSelect::Enter()
{
	TEXTURE_MGR.Load("graphics/background.png");
	TEXTURE_MGR.Load("graphics/player.png");
	TEXTURE_MGR.Load("graphics/player2.png");
	TEXTURE_MGR.Load("graphics/back.png");
	Scene::Enter();
}

void SceneSelect::Exit()
{
	std::cout << "SceneSelect::Exit()" << std::endl;
	Scene::Exit();
	TEXTURE_MGR.Unload("graphics/background.png");
	TEXTURE_MGR.Unload("graphics/player.png");
	TEXTURE_MGR.Unload("graphics/player2.png");
	TEXTURE_MGR.Unload("graphics/back.png");
}

void SceneSelect::Update(float dt)
{
	Scene::Update(dt);
	if (Player1->getisclicked())
	{
		Player::isplayer1 = true;
		SCENE_MGR.ChangeScene(SceneIds::Dev3);
	}

	if (Player2->getisclicked())
	{
		Player::isplayer1 = false;
		SCENE_MGR.ChangeScene(SceneIds::Dev3);
	}
	if (back->getisclicked() || InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneIds::ModSelect);
	}

}

void SceneSelect::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
