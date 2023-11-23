#include "GameManagement/GamePlay.h"

#include "GameManagement/Utilities.h"
#include "GameManagement/GameData.h"
#include "Objects/PlayerManager.h"
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

		void GamePlayLoop(bool& enteredNewScene, Scenes& currentScene, bool isMultiplayer)
		{
			gd.isMultiplayer = isMultiplayer;

			if (enteredNewScene || gd.shouldRestart)
			{
				game::Start();
				enteredNewScene = false;
			}

			if (!gd.isPaused && !gd.isGameOver && !gd.areRulesBeingShown)
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
			playerManager::Start(gd.isMultiplayer);
			obstaclesManager::Start();
			backGround::Start();
			uiManager::init();

			gd.shouldRestart = false;
			gd.isGameOver = false;
			gd.isPaused = false;
		}
		void Update()
		{
			playerManager::Update(gd.isMultiplayer, gd.isGameOver);
			obstaclesManager::Update();
			backGround::Update();
			CheckCollisions(gd.isMultiplayer);
			uiManager::update();

			if (IsMouseButtonPressed(2) || IsKeyPressed(KEY_ESCAPE))
				gd.isPaused = true;
		}

		void Draw()
		{
			BeginDrawing();
			ClearBackground(BLACK);
			backGround::Draw();
			playerManager::Draw(gd.isMultiplayer);
			obstaclesManager::Draw();
			uiManager::draw(gd.isMultiplayer);
			EndDrawing();
		}

		void PauseUpdate(Scenes& scene)
		{
			if (gd.areRulesBeingShown)
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
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
				if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE) || IsKeyPressed(KEY_ESCAPE))
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

			if (gd.areRulesBeingShown)
					userInterface::RulesDraw();
			else if (gd.isGameOver)
				userInterface::GameOverPanelDraw(gd.menuButton, gd.restartButton, gd.isMultiplayer);
			else
				userInterface::PausePanelDraw(gd.menuButton);

			EndDrawing();
		}
	}
}
