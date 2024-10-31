#include "stdafx.h"
#include "UiScore2.h"

UiScore2::UiScore2(const std::string& fontId, const std::string& name)
	: TextGo(fontId, name)
{
	sortingLayer = SortingLayers::UI;
}

void UiScore2::Reset()
{
	TextGo::Reset();
	SetScore2(0);
}

void UiScore2::SetScore2(int score)
{
	this->score = score;
	text.setString(textFormat + std::to_string(this->score));
	SetOrigin(originPreset);
}


