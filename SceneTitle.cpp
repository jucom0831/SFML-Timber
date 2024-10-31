#include "stdafx.h"
#include "SceneTitle.h"
#include "SpriteGo.h"

SceneTitle::SceneTitle() : Scene(SceneIds::Title)
{
}

void SceneTitle::Init()
{
	std::cout << "SceneTitle::Init()" << std::endl;
	
	GameObject* obj = AddGo(new SpriteGo("graphics/background1.png"));
	obj->sortingLayer = SortingLayers::Background;
	obj->sortingOrder = -1;
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });

	Scene::Init();
}


void SceneTitle::Enter()
{
	TEXTURE_MGR.Load("graphics/background1.png");

	Scene::Enter();

}
void SceneTitle::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter) || InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	{
		SCENE_MGR.ChangeScene(SceneIds::ModSelect);
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}
}

void SceneTitle::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void SceneTitle::Exit()
{
	std::cout << "SceneTitle::Exit()" << std::endl;
	Scene::Exit();
	TEXTURE_MGR.Unload("graphics/background1.png");
	
}

