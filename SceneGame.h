#pragma once
#include "Scene.h"
class Tree;
class PlayerMulti;
class TextGo;
class UiScore;
class UiTimebar;
class UiAreaBound;
class SceneGame :
	public Scene
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
	int playerCnt = 1;
	Status currentStatus = Status::Awake;
	struct PlayerData
	{
		Tree* tree;
		PlayerMulti* player;
		UiScore* uiScore;
		UiTimebar* uiTimer;
		UiAreaBound* uiBound;
		int score = 0;
		float timer = 0.f;
	};

	TextGo* centerMsg;
	float gameTime = 5.f;

	std::vector<PlayerData> playerData;
	void InitPlayerData(PlayerData& data, int index);
	void ResetPlayerData(PlayerData& data, int index);

	sf::Sound sfxDeath;
	sf::Sound sfxTimeOut;

	std::string sbIdDeath = "sound/death.wav";
	std::string sbIdTimeOut = "sound/out_of_time.wav";

	sf::Keyboard::Key keySetting[4][2];
public:
	SceneGame(int playerCnt = 1);
	~SceneGame() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;

	void Draw(sf::RenderWindow& window) override;

	void SetCenterMessage(const std::string& msg);
	void SetVisibleCenterMessage(bool visible);

	void SetScore(int score, int index = 0);

	void SetStatus(Status newStatus);
	void UpdateAwake(float dt);
	void UpdateGame(float dt, int index=0);
	void UpdateGameOver(float dt);
	void UpdatePause(float dt);

	void OnChop(Sides side, int index = 0);

};

