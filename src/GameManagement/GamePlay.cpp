#include "GameManagement/GamePlay.h"

#include "GameManagement/Utilities.h"
#include "GameManagement/GameData.h"
#include "Objects/Player.h"
#include "Objects/Obstacle.h"
#include "Objects/BackGround.h"
#include "GameManagement/CollisionHandler.h"
#include "GameManagement/UI.h"

namespace flappyBird
{
	namespace game
	{
		static GameData gd;

		void Start();
		void Update();
		void Draw();

		void GamePlayLoop(bool& isNewScene)
		{
			if (isNewScene || gd.shouldRestart)
			{
				game::Start();
				isNewScene = false;
				gd.shouldRestart = false;
			}

			game::Update();
			game::Draw();
		}

		void Start()
		{
			player::Start();
			obstacle::Start();
			backGround::Start();
		}
		void Update()
		{
			player::Update(gd.shouldRestart);
			obstacle::Update();
			backGround::Update();
			CheckCollisions();
		}
		void Draw()
		{
			BeginDrawing();
			ClearBackground(BLACK);
			backGround::Draw();
			player::Draw();
			obstacle::Draw();
			userInterface::DrawVersionText();
			EndDrawing();
		}
	}
}