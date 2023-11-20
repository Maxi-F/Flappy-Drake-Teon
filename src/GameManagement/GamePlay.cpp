#include "GameManagement/GamePlay.h"

#include "GameManagement/Utilities.h"
#include "GameManagement/GameData.h"
#include "Objects/Player.h"
#include "GameManagement/ObstaclesManager.h"
#include "Objects/BackGround.h"
#include "GameManagement/CollisionHandler.h"
#include "GameManagement/UIManager.h"
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

			if (!gd.isPaused && !gd.isGameOver)
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

		void SetIsGameOver(bool value) {
			gd.isGameOver = value;
		}

		void Start()
		{
			player::Start();
			obstaclesManager::Start();
			backGround::Start();
			uiManager::init();

			gd.shouldRestart = false;
			gd.isGameOver = false;
			gd.isPaused = false;
		}
		void Update()
		{
			player::Update(gd.shouldRestart);
			obstaclesManager::Update();
			backGround::Update();
			CheckCollisions();
			uiManager::update();

			if (IsMouseButtonPressed(2) || IsKeyPressed(KEY_ESCAPE))
				gd.isPaused = true;
		}

		void Draw()
		{
			BeginDrawing();
			ClearBackground(BLACK);
			backGround::Draw();
			player::Draw();
			obstaclesManager::Draw();
			uiManager::draw();
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

				if (gd.shouldRestart) {
					gd.isGameOver = false;
				}
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