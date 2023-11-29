#pragma once
#include "GameManagement/Scenes.h"

namespace flappyBird
{
	struct SceneManager
	{
		Scenes currentScene {};
		Scenes prevScene {};
		bool enteredNewScene {};

		bool isSinglePlayer{};
		bool isPaused = false;
	};
};