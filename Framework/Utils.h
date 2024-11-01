#pragma once

class Utils // Ŭ���� ��ƿ��Ƽ�� ��Ƴ��� ��
{
private:
	static std::mt19937 generator;
	// static �����Լ�
	// static�Լ��� Ŭ������ intstance���̵� ȣ���� �� �ִ�.
	// ���� ���� ������ �Բ� ���ǰų� ��ƿ��Ƽ �Լ��� ���� �� �ִ�.
	// ���� ���� ���� �� �Լ�
	// ���� ���ο����� ������ �� �ֵ��� ������ ������ �� ���ȴ�.�ٸ� ���Ͽ��� �� ������ ������� ���Ѵ�.
	// ���� ����� ��ü�� �������̱� ������ Ư�� ��ü�� �Ӽ��� �ƴ� Ŭ���� ��ü�� �Ӽ����� �ۿ��Ѵ�.
	// c++ǥ�� ���̺귯������ �����ϴ� �ǻ糭�� ������
	// ������ ���� �����ϴµ� ���� ���
	// generator �ǻ糭�� ������
	static const float PI;
	// �������� ���ȭ��Ű�� �Ǽ� PI������

public:
	static void Init();
	// static�����Լ� ��ȯ�� ���� �ʱ�ȭ�Լ�.
	static int RandomRange(int min, int max);
	// static�����Լ� ������ ��ȯ ���� �������Ժ�������(���� ���� �ͺ���, ���� ū �ͱ���)
	static float RandomRange(float min, float max);
	// static�����Լ� �Ǽ��� ��ȯ �������Ժ�������(���� ���� �ͺ���, ���� ū �ͱ���)
	static float RandomValue();	// 0.0f ~ 1.0f
    // static�����Լ� �Ǽ��� ��ƿ��Ƽ ��ȯ RandomValue UutilsŬ������ ���ϴ� �Լ�
	static sf::Vector2f RandomOnUnitCircle();
	// static�����Լ�(Ŭ������ intstance�� ��� ȣ�� ����), sf::Vector2f�� SFML ���̺귯������ �����ϴ� 2D���� Ŭ�����̴�.
	// �� ���ʹ� �ַ� 2D��ǥ�� ũ�⸦ ��Ÿ���µ� ���, RandomUnitCicle�Լ��� �̸�
	static sf::Vector2f RandomInUnitCircle();
	// static�����Լ�(Ŭ������ instance�� ��� ȣ�� ����), sf::Vector2f�� SFML ���̺귯������ �����ϴ� 2D���� Ŭ����
	// 2D��ǥ�� ũ�⸦ ��Ÿ���µ� ���, RandomInUnitCicle�� �Լ��� �̸�
	static float Clamp(float value, float min, float max);
	// static�����Լ�, �Ǽ�����ȯ �����Լ��� ��ȯ�� ���� ���� �� ��, clamp�Լ�(�Ű����� ���Ǽ���, ���� �Ǽ���, ū �Ǽ���)
	static sf::Vector2f SetOrigin(sf::Transformable &obj, Origins preset, const sf::FloatRect bound);
	// static�����Լ�, sf::Vector2f ���ӽ����̽����� ǥ�ض��̺귯������ �����ϴ� Ŭ���� Vector2f��� SetOrigin �Լ� ����(Transformable�� SFML���� �����ϴ� Ŭ���� �� �ϳ�,
	// ��ü�� ��ȯ(�̵�, ȸ��, ũ�� ����)���� �����ϴµ� ��� &obj�� ���纻�� ������ �ʰ�, ������ ��ü �������������ϰ� ����. ���������̴�. Origins �������� preset�� �Ű������̴�
	// sf::FloatRect�� ��ü�� ��� ������ �����ϴµ� ���ȴ�. bound�� ����� �Ű����� 
	static sf::Vector2f SetOrigin(sf::Shape& obj, Origins preset);
	// static �����Լ�, ǥ�ض��̺귯������ �����ϴ� Ŭ���� SetOrigin�Լ��� sf::Shape& obj�� �پ��� ������ ������ �� �ִ�. sf::CicleShape�� sf::RectangleShape���� �ִ�.
	// �������� &obj�� sf::Shape ��ü�� �����Ͽ�, ������ ��ü ���� ����
	static sf::Vector2f SetOrigin(sf::Text& obj, Origins preset);
	// static �����Լ�, ǥ�ض��̺귯������ �����ϴ� Ŭ���� SetOrigin�Լ��� sf::Text�� �ؽ�Ʈ�� ȭ�鿡 �׸��� ���� ���ȴ�. �۲�, ����, ũ��� �پ��� �ؽ�Ʈ�� �پ߾� �Ӽ� ��������
	// sf::Text& obj���� obj�� sf::Text��ü �����ϴ� ���� ���� ������ ��ü ���� ����, Origins �������� preset�� �Ű�����
	static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins preset);
	// static �����Լ�, ǥ�ض��̺귯������ �����ϴ� Ŭ���� SetOrigin�Լ��� sf::Sprite�� 2D�̹����� ȭ�鿡 �������� �� ��� texture�� ������ �����̳� �׷��� ���ø����̼�
	// �̹����� �ִϸ��̼��� ���� �ٷ� �� �ְ� ���ش�, Origins �������� preset�� �Ű�����
	// �������� ��ü��������
};

