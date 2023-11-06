#include "Obstacle.h"

namespace flappyBird
{
	namespace game
	{
		namespace obstacle
		{
			static Obstacle obstacle;
			void SetColliderPosition();

			void Start()
			{
				obstacle.size = { 60, 180 };
				ResetPosition();
				obstacle.speed = 500;

				obstacle.boxCollider = {obstacle.pos.x, obstacle.pos.y, obstacle.size.x, obstacle.size.y};
			}

			void Update()
			{
				obstacle.pos.x -= obstacle.speed * GetFrameTime();

				SetColliderPosition();

				if (obstacle.pos.x + obstacle.size.x < 0)
					ResetPosition();
			}

			void Draw()
			{
				DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), static_cast<int>(obstacle.size.x), static_cast<int>(obstacle.size.y), WHITE);
#ifdef _DEBUG
				DrawRectangleLines(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.pos.y), static_cast<int>(obstacle.boxCollider.width), static_cast<int>(obstacle.boxCollider.height), GREEN);
#endif
			}

			void ResetPosition()
			{
				bool doesObstacleSpawnUp = GetRandomValue(0, 1) == 0;
				float posY = doesObstacleSpawnUp ? 0 : GetScreenHeight() - obstacle.size.y;
				obstacle.pos = { static_cast<float>(GetScreenWidth()), posY };
			}

			Rectangle GetCollider()
			{
				return obstacle.boxCollider;
			}

			void SetColliderPosition()
			{
				obstacle.boxCollider.x = obstacle.pos.x;
				obstacle.boxCollider.y = obstacle.pos.y;
			}
		}
	}
}
