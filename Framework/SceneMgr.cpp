#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneDev3.h"
#include "SceneDev2.h"
#include "SceneTitle.h"
#include "SceneSelect.h"
#include "SceneModSelect.h"
void SceneMgr::Init()
{
	scenes.push_back(new SceneTitle());
	scenes.push_back(new SceneDev1());
	scenes.push_back(new SceneDev2());
	scenes.push_back(new SceneDev3());	
	scenes.push_back(new SceneSelect());
	scenes.push_back(new SceneModSelect());

	for (auto scene : scenes)
	{
		scene->Init();
	}

	currentScene = SceneIds::Title;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Release()
{
	for (auto scene : scenes)
	{
		scene->Release();
		delete scene;
	}
	scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	nextScene = id;
}

void SceneMgr::Update(float dt)
{
	scenes[(int)currentScene]->Update(dt);
}

void SceneMgr::LateUpdate(float dt)
{
	scenes[(int)currentScene]->LateUpdate(dt);
}

void SceneMgr::OnPreDraw()
{
	scenes[(int)currentScene]->OnPreDraw();
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	OnPreDraw();
	scenes[(int)currentScene]->Draw(window);
	OnPostDraw();
}

void SceneMgr::OnPostDraw()
{
	scenes[(int)currentScene]->OnPostDraw();
	if (nextScene != SceneIds::None)
	{
		scenes[(int)currentScene]->Exit();
		currentScene = nextScene;
		nextScene = SceneIds::None;
		scenes[(int)currentScene]->Enter();
	}
}
