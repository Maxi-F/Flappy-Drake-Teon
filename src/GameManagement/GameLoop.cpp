#include "GameManagement/GameLoop.h"

#include "raylib/raylib.h"

#include "GameManagement/Gameplay.h"

namespace flappyBird
{
	void RunGame()
	{
		InitWindow(1280, 720, "Flappy Drake");

		bool newScene = true;
		while (!WindowShouldClose())
		{
			if (newScene)
			{
				game::Start();
				newScene = false;
			}

			game::Update();
			game::Draw();
		}
		CloseWindow();
	}
}