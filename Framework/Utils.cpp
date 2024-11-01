
#include "stdafx.h"
// ���� �����ϵ� ���
// ���� ��������ʴ� ǥ�� ���̺귯���� �ܺ� ���̺귯�� ������� ����
#include "Utils.h"
#include <cmath>
// ǥ�� ���� ���̺귯��, �پ��� ���� �Լ� ����

std::mt19937 Utils::generator;
// �������� ����?
// std:: �̸������� ��������ν�, ǥ�ض��̺귯���� ���ǵ� Ÿ������ �˷��ش�.
// mt19937�� c++ ǥ�� ���̺귯������ �����ϴ� �ǻ糭�� ������
// generator�� ����ϴ� ������ ���� ���� ������ �ϰ����� ǰ¡�� �����ϱ����ؼ�
// generator��  std::mt19937Ÿ���� ��ü�� �ǻ糭�� �����⸦ �ʱ�ȭ�� ��
const float Utils::PI = acosf(-1.f);
// ���� ���� �ʱ�ȭ ����?
// �Ǽ� ��ƿ��Ƽ Ŭ���� ���� ��� ����, ::�� ���� ������ ���ӽ����̽���, Ŭ������ ��� ������ �����ϰ� ��Ȯ�ϰ� �ϱ����ؼ�
// acosf�� �ڻ����� ���Լ��� �ǹ��ϰ�,  -1�� �ڻ����� 180�̴�.
void Utils::Init()
// ��ƿ��Ƽ �ʱ�ȭ ��ȯ�� ����
{
    std::random_device rd;
// random_device�� c++ ǥ�� ���̺귯������ �����Ǵ� Ŭ����, ���� �������� � ü���� ��Ʈ���� �ҽ� ��� ������ �������� ����
// rd�� random_device Ŭ������ �ν��Ͻ�(��ü)�ǹ�
// ������ ��ü�� ���� ������ �����Ͱ� ����, ��ü�� Ŭ�����κ��� ������ ��ü
    generator.seed(rd());
// �������� ���� �ʱ�ȭ
// generator ���������� ��ü(std::mt19937)
// seed ���� ������ ��ü�� �ʱ�ȭ�ϴ� �Լ�
// rd ������ �õ� ���� �����ϴ� ��ü(std::random_device)
// rd�� random_device�� ��ü�̰�, rd()�� random_device��ü�� ȣ���Ͽ� ������ ���ڸ� ����
}

int Utils::RandomRange(int min, int max)
// ������ ��ƿ��Ʈ ��ȯ(������ ��������, ������ ����ū)
{
    std::uniform_int_distribution<int> dist(min, max);
    // static�����Լ� ������ ��ȯ �������Ժ�������(���� ���� �ͺ���, ���� ū �ͱ���)
    return dist(generator);
    // dist��ü ���� �ش�. (uniform_int_distribution�� ��ü�μ� ���� ���� �� ��ȯ, ���� ū �� ��ȯ)
}

float Utils::RandomRange(float min, float max)
// �Ǽ��� ��ƿ��Ƽ ��ȯ(�Ű����� �Ǽ��� ��������, �Ǽ��� ����ū)
{
    std::uniform_real_distribution<float> dist(min, max);
    // static�����Լ� �Ǽ��� ��ȯ �������Ժ�������(���� ���� �ͺ���, ���� ū �ͱ���)
    return dist(generator);
    // dist��ü ���� �ش�. (uniform_real_distribution�� ��ü�μ� ���� ���� ���� ���� ū�� ��ȯ)
}

float Utils::RandomValue()
// �Ǽ��� ��ƿ��Ƽ ��ȯ RandomValue UutilsŬ������ ���ϴ� �Լ�
{
    return RandomRange(0.f, 1.f);
    // 0.0���� 1.0������ ������ ��ȯ�ϴ� �Լ�, float�� ��ȯ
}

sf::Vector2f Utils::RandomOnUnitCircle()
// Ŭ���� 2�� ��� sf::Vector2f�� Utils�� RandomOnUnitCicle�� �Լ�(�Ű����� ����)
{
    float angle = RandomRange(0.f, 2.f * PI);
    // �Ǽ��� ���� 0.0�� 2����(�ѹ����� ���� 360��)������ ������ ���� ���� �Լ� 
    return sf::Vector2f(std::cosf(angle), std::sinf(angle));
    // sf::Vector2f(�ڻ���(����), ����(����))
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
