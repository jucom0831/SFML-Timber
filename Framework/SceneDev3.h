#include <stdafx.h>
#pragma once
#include "Scene.h"

class Tree;
class Player;
class TextGo;
class UiScore;
class UiTimebar;
class Player2;
class Tree2;
class UiScore2;
class UiTimebar2;


class SceneDev3 : public Scene
{
public:
	enum class Status
	{
		Awake,
		Game,
		GameOver,
		Pause,
	};

protected:
	Status currentStatus = Status::Awake;

	Tree* tree;
	Tree2* tree2;
	Player* player;
	Player2* player2;

	TextGo* centerMsg;
	UiScore* uiScore;
	UiTimebar* uiTimer;
	UiScore2* uiScore2;
	UiTimebar2* uiTimer2;

	int score = 0;
	int score2 = 0;
	float timer = 0.f;
	float timer2 = 0.f;
	float gameTime = 5.f;

	sf::Sound sfxDeath;
	sf::Sound sfxTimeOut;

	std::string sbIdDeath = "sound/death.wav";
	std::string sbIdTimeOut = "sound/out_of_time.wav";

public:
	SceneDev3();
	~SceneDev3() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;

	void Draw(sf::RenderWindow& window) override;

	void SetCenterMessage(const std::string& msg);
	void SetVisibleCenterMessage(bool visible);

	void SetScore(int score);
	void SetScore2(int score2);

	void SetStatus(Status newStatus);
	void UpdateAwake(float dt);
	void UpdateGame(float dt);
	void UpdateGameOver(float dt);
	void UpdatePause(float dt);

	void OnChop(Sides side);
	void OnChop2(Sides side);
};
