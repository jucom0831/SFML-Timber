#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "CloudGo.h"
#include "Tree.h"
#include "PlayerMulti.h"
#include "TextGo.h"
#include "UiScore.h"
#include "UiTimebar.h"
#include "UiAreaBound.h";

void SceneGame::InitPlayerData(PlayerData& data, int index)
{
	data.tree = AddGo(new Tree("Tree"));
	data.player = AddGo(new PlayerMulti(index,"Player"));
	data.player->SetKeyBoard(keySetting[index][0], keySetting[index][1]);
	data.uiScore = AddGo(new UiScore("fonts/KOMIKAP_.ttf", "Ui Score"));
	data.uiTimer = AddGo(new UiTimebar("Ui Timer"));
	data.uiBound = AddGo(new UiAreaBound("fonts/KOMIKAP_.ttf"));
}

void SceneGame::ResetPlayerData(PlayerData& data, int index)
{
	data.tree->SetScale({ 1.0f / playerCnt, 1 });
	data.tree->SetPosition({ (1920.f / (2 * playerCnt)) * (2 * index + 1), 1080.f - 200.f });
	data.player->Reset();
	data.player->SetPosition({ (1920.f / (2 * playerCnt)) * (2 * index + 1), 1080.f - 200.f });
	data.uiScore->text.setCharacterSize(75);
	data.uiScore->text.setFillColor(sf::Color::White);
	data.uiScore->SetPosition({ (1920.f / (2 * playerCnt)) * (2 * index), 30.f });
	data.uiTimer->SetOrigin(Origins::ML);
	data.uiTimer->Set({ (1920.f / playerCnt) - 20, 100.f }, sf::Color::Red);
	data.uiTimer->SetPosition({ (1920.f / (2 * playerCnt)) * (2 * index), 1080.f - 100.f });
	data.uiTimer->SetValue(1.f);
	data.uiBound->SetRectangle(sf::FloatRect((1920.f / playerCnt) * index, 0, 1920.f / playerCnt, 1080.f));
	data.uiBound->SetString("Player " + std::to_string(index+1), 30);
	data.timer = gameTime;
	data.score = 0;
	data.uiScore->SetScore(data.score);
	data.tree->Reset();
}

SceneGame::SceneGame(int playerCnt)
	: Scene(SceneIds::MultiGame), playerCnt(playerCnt)
{
	playerData.resize(playerCnt);
	keySetting[0][0] = sf::Keyboard::Key::Left;
	keySetting[0][1] = sf::Keyboard::Key::Right;

	keySetting[1][0] = sf::Keyboard::Key::A;
	keySetting[1][1] = sf::Keyboard::Key::D;

	keySetting[2][0] = sf::Keyboard::Key::T;
	keySetting[2][1] = sf::Keyboard::Key::U;

	keySetting[3][0] = sf::Keyboard::Key::J;
	keySetting[3][1] = sf::Keyboard::Key::L;
}

void SceneGame::Init()
{
	std::cout << "SceneGame::Init()" << std::endl;

	GameObject* bg = AddGo(new SpriteGo("graphics/background.png"));
	bg->sortingLayer = SortingLayers::Background;
	bg->sortingOrder = -1;
	bg->SetOrigin(Origins::MC);
	bg->SetPosition({ 1920 / 2, 1080 / 2 });

	for (int i = 0; i < 3; ++i)
	{
		CloudGo* cloud = AddGo(new CloudGo("graphics/cloud.png"));
		cloud->sortingLayer = SortingLayers::Background;
		cloud->sortingOrder = 0;
	}

	TEXTURE_MGR.Load("graphics/tree.png");
	TEXTURE_MGR.Load("graphics/branch.png");
	TEXTURE_MGR.Load("graphics/player.png");
	TEXTURE_MGR.Load("graphics/rip.png");
	TEXTURE_MGR.Load("graphics/axe.png");
	TEXTURE_MGR.Load("graphics/dust.png");


	for (int i = 0; i < playerCnt; i++)
	{
		InitPlayerData(playerData[i], i);
	}

	centerMsg = AddGo(new TextGo("fonts/KOMIKAP_.ttf", "Center Message"));
	centerMsg->sortingLayer = SortingLayers::UI;
	Scene::Init();

	currentStatus = Status::Awake;
	for (int i = 0; i < playerCnt; i++)
	{
		ResetPlayerData(playerData[i], i);
	}
	centerMsg->text.setCharacterSize(100);
	centerMsg->text.setFillColor(sf::Color::White);
	centerMsg->SetPosition({ 1920.f / 2.f, 1080.f / 2.f });
}

void SceneGame::Enter()
{
	TEXTURE_MGR.Load("graphics/background.png");
	TEXTURE_MGR.Load("graphics/cloud.png");
	TEXTURE_MGR.Load("graphics/tree.png");
	TEXTURE_MGR.Load("graphics/branch.png");
	TEXTURE_MGR.Load("graphics/log.png");
	TEXTURE_MGR.Load("graphics/player.png");
	TEXTURE_MGR.Load("graphics/rip.png");
	TEXTURE_MGR.Load("graphics/axe.png");
	TEXTURE_MGR.Load("graphics/dust.png");
	FONT_MGR.Load("fonts/KOMIKAP_.ttf");
	SOUNDBUFFER_MGR.Load("sound/chop.wav");
	SOUNDBUFFER_MGR.Load(sbIdDeath);
	SOUNDBUFFER_MGR.Load(sbIdTimeOut);

	sfxDeath.setBuffer(SOUNDBUFFER_MGR.Get(sbIdDeath));
	sfxTimeOut.setBuffer(SOUNDBUFFER_MGR.Get(sbIdTimeOut));

	for (int i = 0; i < playerCnt; i++)
	{
		playerData[i].player->SetSceneGame(this);
	}
	Scene::Enter();
	SetStatus(Status::Awake);
}

void SceneGame::Exit()
{
	std::cout << "SceneGame::Exit()" << std::endl;
	Scene::Exit();

	TEXTURE_MGR.Unload("graphics/cloud.png");
	TEXTURE_MGR.Unload("graphics/background.png");
	TEXTURE_MGR.Unload("graphics/tree.png");
	TEXTURE_MGR.Unload("graphics/branch.png");
	TEXTURE_MGR.Unload("graphics/log.png");
	TEXTURE_MGR.Unload("graphics/player.png");
	TEXTURE_MGR.Unload("graphics/rip.png");
	TEXTURE_MGR.Unload("graphics/axe.png");
	TEXTURE_MGR.Unload("graphics/dust.png");
	FONT_MGR.Unload("fonts/KOMIKAP_.ttf");
	SOUNDBUFFER_MGR.Unload("sound/chop.wav");
	SOUNDBUFFER_MGR.Unload("sound/death.wav");
	SOUNDBUFFER_MGR.Unload("sound/out_of_time.wav");

}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
	}

	switch (currentStatus)
	{
	case SceneGame::Status::Awake:
		UpdateAwake(dt);
		break;
	case SceneGame::Status::Game:
		for (int i = 0; i < playerCnt; i++)
			UpdateGame(dt, i);
		break;
	case SceneGame::Status::GameOver:
		UpdateGameOver(dt);
		break;
	case SceneGame::Status::Pause:
		UpdatePause(dt);
		break;
	}
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void SceneGame::SetCenterMessage(const std::string& msg)
{
	centerMsg->text.setString(msg);
	centerMsg->SetOrigin(Origins::MC);
}

void SceneGame::SetVisibleCenterMessage(bool visible)
{
	centerMsg->SetActive(visible);
}

void SceneGame::SetScore(int score, int index)
{
	playerData[index].score = score;
	playerData[index].uiScore->SetScore(playerData[index].score);
}

void SceneGame::SetStatus(Status newStatus)
{
	Status prevStatus = currentStatus;
	currentStatus = newStatus;

	switch (currentStatus)
	{
	case SceneGame::Status::Awake:
		FRAMEWORK.SetTimeScale(0.f);
		SetVisibleCenterMessage(true);
		SetCenterMessage("Press Enter To Start!!");
		for (int i = 0; i < playerCnt; i++)
		{
			ResetPlayerData(playerData[i], i);
		}
		break;
	case SceneGame::Status::Game:
		if (prevStatus == Status::GameOver)
		{
			for (int i = 0; i < playerCnt; i++)
			{
				ResetPlayerData(playerData[i], i);
			}
		}
		FRAMEWORK.SetTimeScale(1.f);
		SetVisibleCenterMessage(false);
		break;
	case SceneGame::Status::GameOver:
		FRAMEWORK.SetTimeScale(0.f);
		SetVisibleCenterMessage(true);
		break;
	case SceneGame::Status::Pause:
		FRAMEWORK.SetTimeScale(0.f);
		SetVisibleCenterMessage(true);
		SetCenterMessage("PAUSE! ESC TO RESUME!");
		break;
	}
}

void SceneGame::UpdateAwake(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		SetStatus(Status::Game);
	}
}

void SceneGame::UpdateGame(float dt, int index)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		SetStatus(Status::Pause);
		return;
	}

	playerData[index].timer = Utils::Clamp(playerData[index].timer - dt, 0.f, gameTime);
	playerData[index].uiTimer->SetValue(playerData[index].timer / gameTime);
	if (playerData[index].timer <= 0.f)
	{
		sfxTimeOut.play();

		playerData[index].player->OnDie();
		SetCenterMessage( "Player"+std::to_string(index + 1) + " Time Over!");
		for (int i = 0; i < playerCnt; i++)
		{
			playerData[index].player->OnDie();
		}
		SetStatus(Status::GameOver);
		return;
	}
}

void SceneGame::UpdateGameOver(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		SetStatus(Status::Game);
	}
}

void SceneGame::UpdatePause(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		SetStatus(Status::Game);
	}
}

void SceneGame::OnChop(Sides side, int index)
{
	Sides branchSide = playerData[index].tree->Chop(side);
	if (playerData[index].player->GetSide() == branchSide)
	{
		sfxDeath.play();

		playerData[index].player->OnDie();
		SetCenterMessage("Player"+ std::to_string(index + 1)+ " Die!");
		for (int i = 0; i < playerCnt; i++)
		{
			playerData[index].player->OnDie();
		}
		SetStatus(Status::GameOver);
	}
	else
	{
		SetScore(playerData[index].score + 100);
		playerData[index].timer += 1.f;
	}
}
