#pragma once
#include "GameObject.h"
class UiAreaBound :
    public GameObject
{
public:
    UiAreaBound(const std::string& fontid, const std::string& name="");
    ~UiAreaBound();

    void Init();
    void Reset();
    void Draw(sf::RenderWindow& window);

    void SetString(const std::string& str, int size);
    void SetRectangle(const sf::FloatRect& rect);
private:
    sf::RectangleShape rect;
    sf::Text text;
    std::string fontid;
};

