#include "GameManagement/GamePlay.h"

#include "GameManagement/Utilities.h"
#include "GameManagement/GameData.h"
#include "Objects/Player.h"
#include "Objects/Obstacle.h"
#include "GameManagement/CollisionHandler.h"
#include "GameManagement/UI.h"

namespace flappyBird
{
	namespace game
	{
		static GameData gd;

		void Start()
		{
			player::Start();
			obstacle::Start();
		}
		void Update()
		{
			player::Update();
			obstacle::Update();
			CheckCollisions();
		}
		void Draw()
		{
			BeginDrawing();
			ClearBackground(BLACK);
			player::Draw();
			obstacle::Draw();
			userInterface::DrawVersionText();

			EndDrawing();
		}
	}
}