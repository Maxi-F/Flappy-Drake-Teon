#pragma once
#include "GameManagement/Utilities.h"
#include "GameManagement/Scenes.h"

namespace flappyBird
{
	struct Button
	{
		utilities::Rect buttonRect;
		Scenes sceneTo;
		const char* text;
		int fontSize = 70;
		Color textColor = WHITE;
		Color currentTextColor = WHITE;
		Color bgColor = BLACK;
		Color currentBgColor = BLACK;

		float textHeightSpacerMultiplier = 2.25f;
		float textPositionX = 15;

		bool wasPressed{ false };
	};

	void ButtonCollisionCheck(Button& button, Scenes& scene);
	void ItchPageButtonCollisionCheck(Button& button, const char* link);
	void CreditsButtonCollisionCheck(Button& button, bool& creditsScreen);
	void ResetButtonCollisionCheck(Button& button, bool& restartGame);
	void ButtonDraw(Button& button, bool drawRectangle);
};