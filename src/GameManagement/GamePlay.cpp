#include "GameManagement/GamePlay.h"

#include "GameManagement/Utilities.h"
#include "GameManagement/GameData.h"
#include "Objects/Player.h"
#include "Objects/Obstacle.h"
#include "Objects/BackGround.h"
#include "GameManagement/CollisionHandler.h"
#include "Objects/UI.h"

namespace flappyBird
{
	namespace game
	{
		static GameData gd;

		void Start();
		void Update();
		void Draw();

		void PauseUpdate(Scenes& scene);
		void PauseDraw();

		void GamePlayLoop(bool& enteredNewScene, Scenes& currentScene)
		{
			if (enteredNewScene || gd.shouldRestart)
			{
				game::Start();
				enteredNewScene = false;
			}

			if (!gd.isPaused)
			{
				game::Update();
				game::Draw();
			}
			else
			{
				ShowCursor();
				PauseUpdate(currentScene);
				PauseDraw();
			}

		}

		void Start()
		{
			player::Start();
			obstacle::Start();
			backGround::Start();

			gd.shouldRestart = false;
			gd.isPaused = false;
		}
		void Update()
		{
			player::Update(gd.shouldRestart);
			obstacle::Update();
			backGround::Update();
			CheckCollisions();

			if (IsMouseButtonPressed(2) || IsKeyPressed(KEY_ESCAPE))
				gd.isPaused = true;
		}

		void Draw()
		{
			BeginDrawing();
			ClearBackground(BLACK);
			backGround::Draw();
			player::Draw();
			obstacle::Draw();
			EndDrawing();
		}

		void PauseUpdate(Scenes& scene)
		{
			if (gd.areRulesBeingShown)
			{
				if (IsMouseButtonPressed(0))
				{
					gd.isPaused = false;
					gd.areRulesBeingShown = false;
				}
			}
			else if (gd.isGameOver)
			{
				ButtonCollisionCheck(gd.menuButton, scene);
				ResetButtonCollisionCheck(gd.restartButton, gd.shouldRestart);
			}
			else
			{
				ButtonCollisionCheck(gd.menuButton, scene);
				if (IsMouseButtonPressed(2) || IsKeyPressed(KEY_ESCAPE))
				{
					gd.isPaused = false;
				}
			}
		}

		void PauseDraw()
		{
			BeginDrawing();

			ClearBackground(BLACK);
			Color panelColor = BLACK;

			if (!gd.areRulesBeingShown)
				panelColor = ColorAlpha(panelColor, 0.010f);

			DrawRectangle(GetScreenWidth() / 2, GetScreenHeight() / 2, GetScreenWidth(), GetScreenHeight(), panelColor);

			/*	if (gd.areRulesBeingShown)
					RulesDraw();
				else */
			if (gd.isGameOver)
				userInterface::GameOverPanelDraw(gd.menuButton, gd.restartButton);
			else
				userInterface::PausePanelDraw(gd.menuButton);

			EndDrawing();
		}
	}
}