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
				DrawRectangle(static_cast<int>(obstacle.pos.x), 0, static_cast<int>(obstacle.size.x), static_cast<int>(obstacle.upperBoxCollider.height), WHITE);
				DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.lowerBoxCollider.y), static_cast<int>(obstacle.size.x), static_cast<int>(obstacle.lowerBoxCollider.height), WHITE);
#ifdef _DEBUG
				DrawRectangleLines(static_cast<int>(obstacle.pos.x), 0, static_cast<int>(obstacle.upperBoxCollider.width), static_cast<int>(obstacle.upperBoxCollider.height), GREEN);
				DrawRectangleLines(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.lowerBoxCollider.y), static_cast<int>(obstacle.lowerBoxCollider.width), static_cast<int>(obstacle.lowerBoxCollider.height), GREEN);
#endif
			}

			void ResetPosition()
			{
				//bool doesObstacleSpawnUp = GetRandomValue(0, 1) == 0;
				float posY = static_cast<float>(GetRandomValue(static_cast<int>(obstacle.obstacleOpeningSize), GetScreenHeight() - static_cast<int>(obstacle.obstacleOpeningSize)));
				//float posY = doesObstacleSpawnUp ? 0 : GetScreenHeight() - obstacle.size.y;
				obstacle.pos = { static_cast<float>(GetScreenWidth()), posY };

				obstacle.upperBoxCollider = { obstacle.pos.x, 0, obstacle.size.x,  obstacle.pos.y - obstacle.obstacleOpeningSize / 2 };
				obstacle.lowerBoxCollider = { obstacle.pos.x, obstacle.pos.y + obstacle.obstacleOpeningSize / 2, obstacle.size.x, static_cast<float>(GetScreenHeight()) - obstacle.pos.y };
			}

			Rectangle GetUpperCollider()
			{
				return obstacle.upperBoxCollider;
			}
			Rectangle GetLowerCollider()
			{
				return obstacle.lowerBoxCollider;
			}

			void SetColliderPosition()
			{
				obstacle.upperBoxCollider.x = obstacle.pos.x;
				obstacle.lowerBoxCollider.x = obstacle.pos.x;
			}
		}
	}
}
