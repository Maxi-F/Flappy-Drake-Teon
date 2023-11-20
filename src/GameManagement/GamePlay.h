#pragma once
#include "GameManagement/Scenes.h"

namespace flappyBird
{
	namespace game
	{
		void GamePlayLoop(bool& enteredNewScene, Scenes& currentScene, bool isMultiplayer);
		void SetIsGameOver(bool value);
	}
}