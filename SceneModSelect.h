#pragma once
#include "Scene.h"
class ButtonGo;

class SceneModSelect :  public Scene
{
private:
	std::string ModSelect;
	ButtonGo* basicMod;
	ButtonGo* twoMod;
	ButtonGo* back;
public:
	
	SceneModSelect();
	~SceneModSelect() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

