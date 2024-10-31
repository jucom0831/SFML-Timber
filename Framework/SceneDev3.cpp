#include "stdafx.h"
#include "SceneDev3.h"
#include "SpriteGo.h"
#include "CloudGo.h"
#include "Tree.h"
#include "Player.h"
#include "TextGo.h"
#include "UiScore.h"
#include "UiTimebar.h"
#include "Tree2.h"
#include "UiScore2.h"
#include "UiTimebar2.h"

SceneDev3::SceneDev3() : Scene(SceneIds::Dev3)
{
}

void SceneDev3::Init()
{
	std::cout << "SceneDev1::Init()" << std::endl;

	GameObject* obj = AddGo(new SpriteGo("graphics/background.png"));
	obj->sortingLayer = SortingLayers::Background;
	obj->sortingOrder = -1;
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });

	for (int i = 0; i < 3; ++i)
	{
		CloudGo* cloud = AddGo(new CloudGo("graphics/cloud.png"));
		cloud->sortingLayer = SortingLayers::Background;
		cloud->sortingOrder = 0;
	}

	TEXTURE_MGR.Load("graphics/tree.png");
	TEXTURE_MGR.Load("graphics/branch.png");
	TEXTURE_MGR.Load("graphics/player.png");
	TEXTURE_MGR.Load("graphics/player2.png");
	TEXTURE_MGR.Load("graphics/rip.png");
	TEXTURE_MGR.Load("graphics/axe.png");

	tree = AddGo(new Tree("Tree"));
	tree2 = AddGo(new Tree2("Tree"));
	player = AddGo(new Player("player"));
	player2 = AddGo(new Player("player"));
	player->SetSprite("graphics/player.png");
	player2->SetSprite("graphics/player2.png");

	centerMsg = AddGo(new TextGo("fonts/KOMIKAP_.ttf", "Center Message"));
	centerMsg->sortingLayer = SortingLayers::UI;

	uiScore = AddGo(new UiScore("fonts/KOMIKAP_.ttf", "Ui Score"));
	uiTimer = AddGo(new UiTimebar("Ui Timer"));

	uiScore2 = AddGo(new UiScore2("fonts/KOMIKAP_.ttf", "Ui Score"));
	uiTimer2 = AddGo(new UiTimebar2("Ui Timer"));

	Scene::Init();

	tree->SetPosition({ 1920.f / 4.5f, 1080.f - 200.f });
	tree2->SetPosition({ 1920.f / 1.3f, 1080.f - 200.f });
	player->SetPosition({ 1920.f / 4.5f, 1080.f - 200.f });
	player2->SetPosition({ 1920.f / 1.3f, 1080.f - 200.f });

	centerMsg->text.setCharacterSize(100);
	centerMsg->text.setFillColor(sf::Color::White);
	centerMsg->SetPosition({ 1920.f / 2.f, 1080.f / 2.f });

	uiScore->text.setCharacterSize(75);
	uiScore->text.setFillColor(sf::Color::White);
	uiScore->SetPosition({ 10.f, 30.f });
	uiTimer->Set({ 500.f, 100.f }, sf::Color::Red);
	uiTimer->SetOrigin(Origins::ML);
	uiTimer->SetPosition({ 1920.f / 4.5f - 250.f, 1080.f - 100.f });

	uiScore2->text.setCharacterSize(75);
	uiScore2->text.setFillColor(sf::Color::White);
	uiScore2->SetPosition({ 1000.f, 30.f });

	uiTimer2->Set({ 500.f, 100.f }, sf::Color::Red);
	uiTimer2->SetOrigin(Origins::ML);
	uiTimer2->SetPosition({ 1920.f / 1.3f - 250.f, 1080.f - 100.f });

}

void SceneDev3::Enter()
{
	TEXTURE_MGR.Load("graphics/background.png");
	TEXTURE_MGR.Load("graphics/cloud.png");
	TEXTURE_MGR.Load("graphics/tree.png");
	TEXTURE_MGR.Load("graphics/branch.png");
	TEXTURE_MGR.Load("graphics/log.png");
	TEXTURE_MGR.Load("graphics/player.png");
	TEXTURE_MGR.Load("graphics/player2.png");
	TEXTURE_MGR.Load("graphics/rip.png");
	TEXTURE_MGR.Load("graphics/axe.png");
	TEXTURE_MGR.Load("graphics/dust.png");
	FONT_MGR.Load("fonts/KOMIKAP_.ttf");
	SOUNDBUFFER_MGR.Load("sound/chop.wav");
	SOUNDBUFFER_MGR.Load(sbIdDeath);
	SOUNDBUFFER_MGR.Load(sbIdTimeOut);

	sfxDeath.setBuffer(SOUNDBUFFER_MGR.Get(sbIdDeath));
	sfxTimeOut.setBuffer(SOUNDBUFFER_MGR.Get(sbIdTimeOut));

	player->SetSceneGame(this);
	player2->SetSceneGame(this);
	player->SetSprite("graphics/player.png");
	player2->SetSprite("graphics/player2.png");
	Scene::Enter();

	SetStatus(Status::Awake);
}

void SceneDev3::Exit()
{
	std::cout << "SceneDev1::Exit()" << std::endl;

	player->SetSceneGame(nullptr);
	player2->SetSceneGame(nullptr);
	//tree->ClearEffectLog();
	tree2->ClearEffectLog();

	Scene::Exit();

	TEXTURE_MGR.Unload("graphics/cloud.png");
	TEXTURE_MGR.Unload("graphics/background.png");
	TEXTURE_MGR.Unload("graphics/tree.png");
	TEXTURE_MGR.Unload("graphics/branch.png");
	TEXTURE_MGR.Unload("graphics/log.png");
	TEXTURE_MGR.Unload("graphics/player.png");
	TEXTURE_MGR.Unload("graphics/player2.png");
	TEXTURE_MGR.Unload("graphics/rip.png");
	TEXTURE_MGR.Unload("graphics/axe.png");
	TEXTURE_MGR.Unload("graphics/dust.png");
	FONT_MGR.Unload("fonts/KOMIKAP_.ttf");
	SOUNDBUFFER_MGR.Unload("sound/chop.wav");
	SOUNDBUFFER_MGR.Unload("sound/death.wav");
	SOUNDBUFFER_MGR.Unload("sound/out_of_time.wav");

}

void SceneDev3::Update(float dt)
{
	Scene::Update(dt);


	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
	}

	switch (currentStatus)
	{
	case SceneDev3::Status::Awake:
		UpdateAwake(dt);
		break;
	case SceneDev3::Status::Game:
		UpdateGame(dt);
		break;
	case SceneDev3::Status::GameOver:
		UpdateGameOver(dt);
		break;
	case SceneDev3::Status::Pause:
		UpdatePause(dt);
		break;
	}
}

void SceneDev3::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void SceneDev3::SetCenterMessage(const std::string& msg)
{
	centerMsg->text.setString(msg);
	centerMsg->SetOrigin(Origins::MC);
}

void SceneDev3::SetVisibleCenterMessage(bool visible)
{
	centerMsg->SetActive(visible);
}

void SceneDev3::SetScore(int score)
{
	this->score = score;
	uiScore->SetScore(this->score);
}
void SceneDev3::SetScore2(int score)
{
	this->score2 = score;
	uiScore2->SetScore2(this->score2);
}

void SceneDev3::SetStatus(Status newStatus)
{
	Status prevStatus = currentStatus;
	currentStatus = newStatus;

	switch (currentStatus)
	{
	case SceneDev3::Status::Awake:
		FRAMEWORK.SetTimeScale(0.f);
		SetVisibleCenterMessage(true);
		SetCenterMessage("Press Enter To Start!!");
		score = 0;
		timer = gameTime;
		score2 = 0;
		timer2 = gameTime;
		SetScore(score);
		SetScore2(score2);
		uiTimer->SetValue(1.f);
		uiTimer2->SetValue(1.f);
		break;
	case SceneDev3::Status::Game:
		if (prevStatus == Status::GameOver)
		{
			score = 0;
			score2 = 0;
			timer = gameTime;
			timer2 = gameTime;

			SetScore(score);
			SetScore2(score2);
			uiTimer->SetValue(1.f);
			uiTimer2->SetValue(1.f);
			player->Reset();
			tree->Reset();
			player2->Reset();
			tree2->Reset();
		}
		FRAMEWORK.SetTimeScale(1.f);
		SetVisibleCenterMessage(false);
		break;
	case SceneDev3::Status::GameOver:
		FRAMEWORK.SetTimeScale(0.f);
		SetVisibleCenterMessage(true);
		break;
	case SceneDev3::Status::Pause:
		FRAMEWORK.SetTimeScale(0.f);
		SetVisibleCenterMessage(true);
		SetCenterMessage("PAUSE! ESC TO RESUME!");
		break;
	}
}

void SceneDev3::UpdateAwake(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		SetStatus(Status::Game);
	}
}

void SceneDev3::UpdateGame(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		SetStatus(Status::Pause);
		return;
	}

	timer = Utils::Clamp(timer - dt, 0.f, gameTime);
	timer2 = Utils::Clamp(timer2 - dt, 0.f, gameTime);

	uiTimer->SetValue(timer / gameTime);
	uiTimer2->SetValue(timer2 / gameTime);

	if (timer <= 0.f)
	{
		sfxTimeOut.play();

		player->OnDie();
		SetCenterMessage("1p Time Over!");
		SetStatus(Status::GameOver);
		return;
	}
	if (timer2 <= 0.f)
	{
		sfxTimeOut.play();

		player2->OnDie();
		SetCenterMessage("2p Time Over!");
		SetStatus(Status::GameOver);
		return;
	}
}

void SceneDev3::UpdateGameOver(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		SetStatus(Status::Game);
	}
}

void SceneDev3::UpdatePause(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		SetStatus(Status::Game);
	}
}

void SceneDev3::OnChop(Sides side)
{
	Sides branchSide = tree->Chop(side);
	if (player->GetSide() == branchSide)
	{
		sfxDeath.play();
		player->OnDie();
		SetCenterMessage("2player Win!");
		SetStatus(Status::GameOver);
	}
	else
	{
		SetScore(score + 100);
		timer += 1.f;
	}

}

void SceneDev3::OnChop2(Sides side)
{
		Sides branchSide2 = tree2->Chop2(side);
		if (player2->GetSide() == branchSide2)
		{
			sfxDeath.play();
			player2->OnDie();
			SetCenterMessage("1player Win!");
			SetStatus(Status::GameOver);
		}
		else
		{
			SetScore2(score2 + 100);
			timer2 += 1.f;
		}
}

