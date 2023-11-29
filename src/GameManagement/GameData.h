#pragma once
#include "Objects/Player.h"
#include "Objects/Obstacle.h"
#include "Objects/Button.h"

namespace flappyBird
{
	namespace game
	{
		struct GameData
		{
			bool areRulesBeingShown = true;
			bool isPaused = false;
			bool isGameOver = false;
			bool isMultiplayer = true;
			float yPosition = 0.0f;
			bool shouldRestart{false};

			const int pointsToSecondPhase = 10;
			bool isPhasingToSecondPhase = false;
			bool isInSecondPhase = false;

			int buttonsFontSize = 50;
			Button restartButton = { { 0, 0 }, Scenes::Game, "Restart" };
			Button menuButton = { { 0, 0 }, Scenes::Menu, "Main Menu" };
		};
	}
}