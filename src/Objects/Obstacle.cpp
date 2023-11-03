#include "Obstacle.h"

namespace flappyBird
{
	namespace game
	{
		namespace obstacle
		{
			void ResetPosition(Obstacle& obstacle);

			void Start(Obstacle& obstacle)
			{
				obstacle.size = { 60, 180 };
				ResetPosition(obstacle);
				obstacle.speed = 500;
			}

			void Update(Obstacle& obstacle)
			{
				obstacle.pos.x -= obstacle.speed * GetFrameTime();

				if (obstacle.pos.x + obstacle.size.x < 0)
					ResetPosition(obstacle);
			}

			void Draw(Obstacle& obstacle)
			{
				DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), static_cast<int>(obstacle.size.x), static_cast<int>(obstacle.size.y), WHITE);
			}

			void ResetPosition(Obstacle& obstacle)
			{
				bool doesObstacleSpawnUp = GetRandomValue(0, 1) == 0;
				float posY = doesObstacleSpawnUp ? 0 : GetScreenHeight() - obstacle.size.y;
				obstacle.pos = { static_cast<float>(GetScreenWidth()), posY };
			}
		}
	}
}
