#pragma once
#include "SpriteGo.h"

class Branch2 : public SpriteGo
{
protected:
	Sides side = Sides::None;

public:
	Branch2(const std::string& texId, const std::string& name = "");
	~Branch2() = default;


	void SetSide(Sides side);
	Sides GetSide() const { return side; }

};
