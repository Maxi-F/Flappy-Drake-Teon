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
			bool areRulesBeingShown = false;
			bool isPaused = false;
			bool isGameOver = false;
			bool isMultiplayer = true;

			bool shouldRestart{false};

			int buttonsFontSize = 50;
			Button restartButton = { {0,0}, Scenes::Game, "Restart" };
			Button menuButton = { {0,0}, Scenes::Menu, "Main Menu" };
		};
	}
}