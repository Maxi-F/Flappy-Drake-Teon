#pragma once
#include "Objects/Button.h"

namespace flappyBird
{
	namespace game
	{
		static const int POINTS_UNTIL_SECOND_PHASE = 10;
		static const int BUTTONS_FONT_SIZE = 50;

		struct GameData
		{
			bool areRulesBeingShown = true;
			bool isPaused = false;
			bool isGameOver = false;
			bool isMultiplayer = true;
			float yPosition = 0.0f;
			bool shouldRestart{false};

			const int pointsToSecondPhase = POINTS_UNTIL_SECOND_PHASE;
			bool isPhasingToSecondPhase = false;
			bool isInSecondPhase = false;

			int buttonsFontSize = BUTTONS_FONT_SIZE;
			Button restartButton = { { 0, 0 }, Scenes::Game, "Restart" };
			Button menuButton = { { 0, 0 }, Scenes::Menu, "Main Menu" };
		};
	}
}