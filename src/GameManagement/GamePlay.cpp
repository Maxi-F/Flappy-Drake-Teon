#include "GameManagement/GamePlay.h"

#include "GameManagement/Utilities.h"
#include "GameManagement/GameData.h"
#include "Objects/Player.h"
#include "Objects/Obstacle.h"

namespace flappyBird
{
	namespace game
	{
		static GameData gd;

		void Start()
		{
			player::Start(gd.player);
			obstacle::Start(gd.obstacle);
		}
		void Update()
		{
			player::Update(gd.player);
			obstacle::Update(gd.obstacle);
		}
		void Draw()
		{
			BeginDrawing();
			ClearBackground(BLACK);
			player::Draw(gd.player);
			obstacle::Draw(gd.obstacle);

			EndDrawing();
		}
	}
}