#include "stdafx.h"
#include "SceneModSelect.h"
#include "SpriteGo.h"
#include "ButtonGo.h"
#include "SceneMgr.h"

SceneModSelect::SceneModSelect() : Scene(SceneIds::ModSelect)
{
}

void SceneModSelect::Init()
{
	std::cout << "SceneModSelect::Init()" << std::endl;
	GameObject* obj = AddGo(new SpriteGo("graphics/background.png"));
	basicMod = AddGo(new ButtonGo("graphics/onemod.png"));
	twoMod = AddGo(new ButtonGo("graphics/twomod.png"));
	back = AddGo(new ButtonGo("graphics/back.png"));
	obj->sortingLayer = SortingLayers::Background;
	obj->sortingOrder = -1;
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });
	basicMod->SetOrigin(Origins::MC);
	basicMod->SetPosition({ 1920/4,1080/ 2 });
	twoMod->SetOrigin(Origins::MC);
	twoMod->SetPosition({ 1920/4 + 900,1080 /2 });
	back->SetOrigin(Origins::TL);
	back->SetPosition({ 0,0 });
	Scene::Init();
}

void SceneModSelect::Enter()
{
	TEXTURE_MGR.Load("graphics/background.png");
	TEXTURE_MGR.Load("graphics/onemod.png");
	TEXTURE_MGR.Load("graphics/twomod.png");
	TEXTURE_MGR.Load("graphics/back.png");
	Scene::Enter();
}

void SceneModSelect::Exit()
{
	std::cout << "SceneModSelect::Exit()" << std::endl;
	Scene::Exit();
	TEXTURE_MGR.Unload("graphics/background.png");
	TEXTURE_MGR.Unload("graphics/onemod.png");
	TEXTURE_MGR.Unload("graphics/twomod.png");
	TEXTURE_MGR.Unload("graphics/back.png");
}

void SceneModSelect::Update(float dt)
{
	Scene::Update(dt);
	if (basicMod->getisclicked())
	{
		SCENE_MGR.ChangeScene(SceneIds::Select);
	}
	if (twoMod->getisclicked())
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev3);
	}
	if (back->getisclicked() || InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneIds::Title);
	}
}

void SceneModSelect::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
