#pragma once
#include "SpriteGo.h"
class ButtonGo : public SpriteGo
{
private:
	bool isclicked = false;
	

	
	


public:
	bool getisclicked() const;
	ButtonGo(const std::string& texId = "", const std::string& name = "");
	~ButtonGo() = default;
	void Reset();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

