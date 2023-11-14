#pragma once
#include "GameManagement/Scenes.h"

namespace flappyBird
{
	namespace game
	{
		void GamePlayLoop(bool& enteredNewScene, Scenes& currentScene);
	}
}