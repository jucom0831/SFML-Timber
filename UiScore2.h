#pragma once
#include "TextGo.h"
class UiScore2 : public TextGo
{
protected:
	std::string textFormat = "SCORE: ";
	int score = 0;

public:
	UiScore2(const std::string& fontId, const std::string& name = "");
	~UiScore2() = default;

	void Reset();
	void SetScore2(int score);
};
