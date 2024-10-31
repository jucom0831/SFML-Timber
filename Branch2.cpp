#include "stdafx.h"
#include "Branch2.h"

Branch2::Branch2(const std::string& texId, const std::string& name)
	: SpriteGo(texId, name)
{
}

void Branch2::SetSide(Sides side)
{
	this->side = side;
	switch (this->side)
	{
	case Sides::Left:
		SetActive(true);
		SetScale({ -1.f, 1.f });
		break;
	case Sides::Right:
		SetActive(true);
		SetScale({ 1.f, 1.f });
		break;
	default:
		SetActive(false);
		break;
	}
}
