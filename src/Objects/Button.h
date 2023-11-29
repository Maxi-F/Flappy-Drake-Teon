#pragma once
#include "GameManagement/Utilities.h"
#include "GameManagement/Scenes.h"

namespace flappyBird
{
	static const int BUTTON_FONT_SIZE = 70;
	static const float TEXT_HEIGHT_SPACER_MULTIPLIER = 2.25f;
	static const float TEXT_POSITION_X = 15.0f;

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

		float textHeightSpacerMultiplier = TEXT_HEIGHT_SPACER_MULTIPLIER;
		float textPositionX = TEXT_POSITION_X;

		bool wasPressed{ false };
	};

	void ButtonCollisionCheck(Button& button, Scenes& scene);
	void ItchPageButtonCollisionCheck(Button& button, const char* link);
	void CreditsButtonCollisionCheck(Button& button, bool& creditsScreen);
	void ResetButtonCollisionCheck(Button& button, bool& restartGame);
	void ButtonDraw(Button& button, bool drawRectangle);
};