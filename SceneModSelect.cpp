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
	obj->sortingLayer = SortingLayers::Background;
	obj->sortingOrder = -1;
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });
	basicMod->SetOrigin(Origins::MC);
	basicMod->SetPosition({ 1920/4,1080/ 2 });
	twoMod->SetOrigin(Origins::MC);
	twoMod->SetPosition({ 1920/4 + 900,1080 /2 });
	Scene::Init();
}

void SceneModSelect::Enter()
{
	TEXTURE_MGR.Load("graphics/background.png");
	TEXTURE_MGR.Load("graphics/onemod.png");
	TEXTURE_MGR.Load("graphics/twomod.png");
	Scene::Enter();
}

void SceneModSelect::Exit()
{
	std::cout << "SceneModSelect::Exit()" << std::endl;
	Scene::Exit();
	TEXTURE_MGR.Unload("graphics/background.png");
	TEXTURE_MGR.Unload("graphics/onemod.png");
	TEXTURE_MGR.Unload("graphics/twomod.png");
}

void SceneModSelect::Update(float dt)
{
	Scene::Update(dt);
	if (basicMod->getisclicked())
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev1);
	}
	if (twoMod->getisclicked())
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
	}
}

void SceneModSelect::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}