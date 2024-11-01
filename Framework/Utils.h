#pragma once

class Utils // 클래스 유틸리티를 모아놓은 곳
{
private:
	static std::mt19937 generator;
	// static 정적함수
	// static함수는 클래스의 intstance없이도 호출할 수 있다.
	// 따라서 정적 변수와 함께 사용되거나 유틸리티 함수로 사용될 수 있다.
	// 정적 전역 변수 및 함수
	// 파일 내부에서만 접근할 수 있도록 범위를 제한할 떄 사용된다.다른 파일에서 이 변수를 사용하지 못한다.
	// 정적 멤버는 객체와 독립적이기 때문에 특정 객체의 속성이 아닌 클래스 자체의 속성으로 작용한다.
	// c++표준 라이브러리에서 제공하는 의사난수 생성기
	// 랜덤한 수를 생성하는데 자주 사용
	// generator 의사난수 생성기
	static const float PI;
	// 정적변수 상수화시키는 실수 PI변수명

public:
	static void Init();
	// static정적함수 반환형 없음 초기화함수.
	static int RandomRange(int min, int max);
	// static정적함수 정수형 반환 랜덤 랜덤정규분포정수(가장 작은 것부터, 가장 큰 것까지)
	static float RandomRange(float min, float max);
	// static정적함수 실수형 반환 랜덤정규분포정수(가장 작은 것부터, 가장 큰 것까지)
	static float RandomValue();	// 0.0f ~ 1.0f
    // static정적함수 실수형 유틸리티 반환 RandomValue Uutils클래스에 속하는 함수
	static sf::Vector2f RandomOnUnitCircle();
	// static정적함수(클래스의 intstance가 없어도 호출 가능), sf::Vector2f는 SFML 라이브러리에서 제공하는 2D백터 클래스이다.
	// 이 벡터는 주로 2D좌표나 크기를 나타내는데 사용, RandomUnitCicle함수의 이름
	static sf::Vector2f RandomInUnitCircle();
	// static정적함수(클래스의 instance가 없어도 호출 가능), sf::Vector2f는 SFML 라이브러리에서 제공하는 2D벡터 클래스
	// 2D좌표나 크기를 나타내는데 사용, RandomInUnitCicle은 함수의 이름
	static float Clamp(float value, float min, float max);
	// static정적함수, 실수형반환 정적함수를 반환형 보다 먼저 쓸 것, clamp함수(매개변수 값실수형, 작은 실수형, 큰 실수형)
	static sf::Vector2f SetOrigin(sf::Transformable &obj, Origins preset, const sf::FloatRect bound);
	// static정적함수, sf::Vector2f 네임스페이스적고 표준라이브러리에서 제공하는 클래스 Vector2f사용 SetOrigin 함수 적고(Transformable은 SFML에서 제공하는 클래스 중 하나,
	// 객체의 변환(이동, 회전, 크기 조정)등을 관리하는데 사용 &obj는 복사본을 만들지 않고, 원래의 객체 직접수정가능하게 만듬. 참조변수이다. Origins 열거형로 preset는 매개변수이다
	// sf::FloatRect는 객체의 경계 영역을 정의하는데 사용된다. bound는 상수형 매개변수 
	static sf::Vector2f SetOrigin(sf::Shape& obj, Origins preset);
	// static 정적함수, 표준라이브러리에서 제공하는 클래스 SetOrigin함수로 sf::Shape& obj는 다양한 도형을 정의할 수 있다. sf::CicleShape나 sf::RectangleShape등이 있다.
	// 참조변수 &obj는 sf::Shape 객체를 참조하여, 원래의 객체 수정 가능
	static sf::Vector2f SetOrigin(sf::Text& obj, Origins preset);
	// static 정적함수, 표준라이브러리에서 제공하는 클래스 SetOrigin함수로 sf::Text는 텍스트를 화면에 그리기 위해 사용된다. 글꼴, 색상, 크기등 다양한 텍스트의 다야안 속성 설정가능
	// sf::Text& obj에서 obj는 sf::Text객체 참조하는 참조 변수 원래의 객체 수정 가능, Origins 열거형로 preset는 매개변수
	static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins preset);
	// static 정적함수, 표준라이브러리에서 제공하는 클래스 SetOrigin함수로 sf::Sprite는 2D이미지를 화면에 렌더링할 때 사용 texture를 적용해 게임이나 그래픽 애플리케이션
	// 이미지나 애니메이션을 쉽게 다룰 수 있게 해준다, Origins 열거형로 preset는 매개변수
	// 참조변수 객체수정가능
};

