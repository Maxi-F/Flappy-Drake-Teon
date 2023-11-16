#include "Obstacle.h"

namespace flappyBird
{
	namespace game
	{
		namespace obstacle
		{
			void SetColliderPosition(Obstacle& obstacle);
			void SetRectangles(Obstacle& obstacle);
			void SetStartPosition(Obstacle& obstacle);


			void Start(Obstacle& obstacle, float offsetX)
			{
				obstacle.offset.x = offsetX;
				obstacle.size = { 60, 180 };
				SetStartPosition(obstacle);
				obstacle.speed = 500;
			}

			void Update(Obstacle& obstacle)
			{
				obstacle.pos.x -= obstacle.speed * GetFrameTime();

				if (obstacle.hasVerticalMovement)
				{
					if (obstacle.pos.y + obstacle.size.y / 2 >= GetScreenHeight() || obstacle.pos.y - obstacle.size.y / 2 <= 0)
						obstacle.verticalSpeed *= -1;

					obstacle.pos.y += obstacle.verticalSpeed * GetFrameTime();
					SetRectangles(obstacle);
				}

				SetColliderPosition(obstacle);


				if (obstacle.pos.x + obstacle.size.x < 0)
					ResetPosition(obstacle);
			}

			void Draw(Obstacle& obstacle)
			{
				DrawRectangle(static_cast<int>(obstacle.pos.x), 0, static_cast<int>(obstacle.size.x), static_cast<int>(obstacle.upperBoxCollider.height), WHITE);
				DrawRectangle(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.lowerBoxCollider.y), static_cast<int>(obstacle.size.x), static_cast<int>(obstacle.lowerBoxCollider.height), WHITE);
#ifdef _DEBUG
				DrawRectangleLines(static_cast<int>(obstacle.pos.x), 0, static_cast<int>(obstacle.upperBoxCollider.width), static_cast<int>(obstacle.upperBoxCollider.height), GREEN);
				DrawRectangleLines(static_cast<int>(obstacle.pos.x), static_cast<int>(obstacle.lowerBoxCollider.y), static_cast<int>(obstacle.lowerBoxCollider.width), static_cast<int>(obstacle.lowerBoxCollider.height), GREEN);
#endif
			}

			void SetStartPosition(Obstacle& obstacle)
			{
				float posY = static_cast<float>(GetRandomValue(static_cast<int>(obstacle.obstacleOpeningSize), GetScreenHeight() - static_cast<int>(obstacle.obstacleOpeningSize)));
				obstacle.pos = { static_cast<float>(GetScreenWidth()) + obstacle.offset.x, posY };
				SetRectangles(obstacle);
			}

			void ResetPosition(Obstacle& obstacle)
			{
				bool doesObstacleMove = GetRandomValue(0, 10) == 0;
				if (doesObstacleMove)
				{
					obstacle.hasVerticalMovement = true;
					bool goesUp = GetRandomValue(0, 1) == 1;
					if ((goesUp && obstacle.verticalSpeed > 0) || (!goesUp && obstacle.verticalSpeed < 0))
						obstacle.verticalSpeed *= -1;
				}
				else
					obstacle.hasVerticalMovement = false;

				float posY = static_cast<float>(GetRandomValue(static_cast<int>(obstacle.obstacleOpeningSize), GetScreenHeight() - static_cast<int>(obstacle.obstacleOpeningSize)));
				//float posY = doesObstacleSpawnUp ? 0 : GetScreenHeight() - obstacle.size.y;
				obstacle.pos = { static_cast<float>(GetScreenWidth()), posY };
				SetRectangles(obstacle);
			}

			void SetRectangles(Obstacle& obstacle)
			{
				obstacle.upperBoxCollider = { obstacle.pos.x, 0, obstacle.size.x,  obstacle.pos.y - obstacle.obstacleOpeningSize / 2 };
				obstacle.lowerBoxCollider = { obstacle.pos.x, obstacle.pos.y + obstacle.obstacleOpeningSize / 2, obstacle.size.x, static_cast<float>(GetScreenHeight()) - obstacle.pos.y };
			}

			Rectangle GetUpperCollider(Obstacle& obstacle)
			{
				return obstacle.upperBoxCollider;
			}
			Rectangle GetLowerCollider(Obstacle& obstacle)
			{
				return obstacle.lowerBoxCollider;
			}

			void SetColliderPosition(Obstacle& obstacle)
			{
				obstacle.upperBoxCollider.x = obstacle.pos.x;
				obstacle.lowerBoxCollider.x = obstacle.pos.x;
			}
		}
	}
}
