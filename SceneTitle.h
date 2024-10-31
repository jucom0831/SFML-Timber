#pragma once
#include "Scene.h"

class SceneTitle :  public Scene
{
private:
	sf::String name;
	// 타이틀 장면 멤버변수 만들기

public:
	SceneTitle();
	~SceneTitle() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;

	void Draw(sf::RenderWindow& window) override;

	
	// 생성자, 소멸자 작성
	// 가상함수 오버라이딩
	// 부모클래스 함수 호출
	// 윈도우 시작 시 나오는 타이틀화면 출력
	// enter나 마우스 오른쪽 클릭 시 게임 진행 멤버함수만들기

};

