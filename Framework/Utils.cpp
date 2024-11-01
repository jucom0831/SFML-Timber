
#include "stdafx.h"
// 사전 컴파일된 헤더
// 자주 변경되지않는 표준 라이브러리나 외부 라이브러리 헤더파일 포함
#include "Utils.h"
#include <cmath>
// 표준 수학 라이브러리, 다양한 수학 함수 포함

std::mt19937 Utils::generator;
// 전역변수 선언?
// std:: 이름공간을 명시함으로써, 표준라이브러리에 정의된 타입임을 알려준다.
// mt19937은 c++ 표준 라이브러리에서 제공하는 의사난수 생성기
// generator을 사용하는 이유는 랜덤 숫자 생성의 일관성과 품징을 보장하기위해서
// generator은  std::mt19937타입의 객체로 의사난수 생성기를 초기화한 것
const float Utils::PI = acosf(-1.f);
// 전역 변수 초기화 선언?
// 실수 유틸리티 클래스 정적 멤버 변수, ::를 쓰는 이유는 네임스페이스나, 클래스의 멤버 변수를 구분하고 명확하게 하기위해서
// acosf는 코사인의 역함수를 의미하고,  -1의 코사인은 180이다.
void Utils::Init()
// 유틸리티 초기화 반환값 없음
{
    std::random_device rd;
// random_device는 c++ 표준 라이브러리에서 제공되는 클래스, 난수 생성위해 운영 체제의 엔트로피 소스 사용 진저한 무작위성 제공
// rd는 random_device 클래스의 인스턴스(객체)의미
// 변수와 객체의 차이 변수는 데이터값 저장, 객체는 클래스로부터 생성된 실체
    generator.seed(rd());
// 난수생성 엔진 초기화
// generator 난수생성기 객체(std::mt19937)
// seed 난수 생성기 객체를 초기화하는 함수
// rd 무작위 시드 값을 생성하는 객체(std::random_device)
// rd는 random_device의 객체이고, rd()는 random_device객체를 호출하여 무작위 숫자를 생성
}

int Utils::RandomRange(int min, int max)
// 정수형 유틸리트 반환(정수형 가장작은, 정수형 가장큰)
{
    std::uniform_int_distribution<int> dist(min, max);
    // static정적함수 정수형 반환 랜덤정규분포정수(가장 작은 것부터, 가장 큰 것까지)
    return dist(generator);
    // dist객체 값을 준다. (uniform_int_distribution의 객체로서 가장 작은 값 반환, 가장 큰 값 반환)
}

float Utils::RandomRange(float min, float max)
// 실수형 유틸리티 반환(매개변수 실수형 가장작은, 실수형 가장큰)
{
    std::uniform_real_distribution<float> dist(min, max);
    // static정적함수 실수형 반환 랜덤정규분포정수(가장 작은 것부터, 가장 큰 것까지)
    return dist(generator);
    // dist객체 값을 준다. (uniform_real_distribution의 객체로서 가장 작은 값과 가장 큰값 반환)
}

float Utils::RandomValue()
// 실수형 유틸리티 반환 RandomValue Uutils클래스에 속하는 함수
{
    return RandomRange(0.f, 1.f);
    // 0.0에서 1.0사이의 랜덤값 반환하는 함수, float값 반환
}

sf::Vector2f Utils::RandomOnUnitCircle()
// 클래스 2개 사용 sf::Vector2f와 Utils의 RandomOnUnitCicle의 함수(매개변수 없음)
{
    float angle = RandomRange(0.f, 2.f * PI);
    // 실수형 변수 0.0과 2파이(한바퀴의 각도 360도)사이의 무작위 값을 생성 함수 
    return sf::Vector2f(std::cosf(angle), std::sinf(angle));
    // sf::Vector2f(코사인(변수), 사인(변수))
}

sf::Vector2f Utils::RandomInUnitCircle()
{
    return RandomOnUnitCircle() * RandomValue();
}

float Utils::Clamp(float value, float min, float max)
{
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

sf::Vector2f Utils::SetOrigin(sf::Transformable& obj, Origins preset, const sf::FloatRect rect)
{
    sf::Vector2f newOrigin(rect.width, rect.height);
    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    obj.setOrigin(newOrigin);
    return newOrigin;
}

sf::Vector2f Utils::SetOrigin(sf::Shape& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utils::SetOrigin(sf::Text& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utils::SetOrigin(sf::Sprite& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}
