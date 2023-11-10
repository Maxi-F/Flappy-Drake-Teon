#include "GameManagement/GameLoop.h"

#include "raylib/raylib.h"

#include "GameManagement/Gameplay.h"
#include "GameManagement/Utilities.h"

namespace flappyBird
{
	void RunGame()
	{
		InitWindow(1280, 720, "Flappy Drake");
		utilities::SetTextures();

		bool newScene = true;
		// newScene Should be the result of Scene prevScene == actualScene
		while (!WindowShouldClose())
		{
			game::GamePlayLoop(newScene);
		}
		CloseWindow();
	}
}