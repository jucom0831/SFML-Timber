#include "stdafx.h"
#include "Framework.h"
#include "SpriteGo.h"

void Framework::Init(int width, int height, const std::string& name)
//반환하지 않음 프레임워크 초기화(3개 매개인자를 줘라[지역변수] int값 가로, int값 세로, 상수화시키는 네임?)
{
	window.create(sf::VideoMode(width, height), name);
    // 윈도우 창 생성(비디오모드(가로, 세로), 윈도우 창 이름 적어놓는 곳)
    Utils::Init();
    // 
    SCENE_MGR.Init();
    InputMgr::Init();
}

void Framework::Do()
{
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        realDeltaTime = deltaTime = dt.asSeconds();
        deltaTime *= timeScale;
        realTime += realDeltaTime;
        time += deltaTime;

        // 이벤트 루프
        InputMgr::Clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            InputMgr::UpdateEvent(event);
        }

        // 업데이트
        SCENE_MGR.Update(deltaTime);
        SCENE_MGR.LateUpdate(deltaTime);

        // 드로우
        window.clear();
        SCENE_MGR.Draw(window);
        window.display();
    }
}

void Framework::Release()
{
    SCENE_MGR.Release();
}
