#pragma once
#include "Scene.h"
class ButtonGo;

class SceneSelect : public Scene
{
private:
	std::string Select;
	ButtonGo* Player1;
	ButtonGo* Player2;

public:
	SceneSelect();
	~SceneSelect() = default;


	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

