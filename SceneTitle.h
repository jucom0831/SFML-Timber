#pragma once
#include "Scene.h"

class SceneTitle :  public Scene
{
private:
	sf::String name;
	// Ÿ��Ʋ ��� ������� �����

public:
	SceneTitle();
	~SceneTitle() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;

	void Draw(sf::RenderWindow& window) override;

	
	// ������, �Ҹ��� �ۼ�
	// �����Լ� �������̵�
	// �θ�Ŭ���� �Լ� ȣ��
	// ������ ���� �� ������ Ÿ��Ʋȭ�� ���
	// enter�� ���콺 ������ Ŭ�� �� ���� ���� ����Լ������

};

