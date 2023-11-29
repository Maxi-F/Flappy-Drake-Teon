#include "Obstacle.h"

#include "GameManagement/TexturesManager.h"

#include <iostream>

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
				const Vector2 OBSTACLE_SIZE = { 60.0f, 180.0f };
				const float OBSTACLE_SPEED = 500.0f;

				obstacle.offset.x = offsetX;
				obstacle.size = OBSTACLE_SIZE;
				obstacle.countedPoint[0] = false;
				obstacle.countedPoint[1] = false;
				SetStartPosition(obstacle);
				obstacle.speed = OBSTACLE_SPEED;
			}

			void Update(Obstacle& obstacle, int& obstaclesPassed, int maxObstacles)
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
				{
					obstaclesPassed++;
					if (obstaclesPassed < maxObstacles) 
					{
						ResetPosition(obstacle);
					}
				}
			}

			void Draw(Obstacle& obstacle)
			{
				Texture treeTexture = utilities::GetTexture(utilities::TextureIdentifier::Tree);

				Rectangle source = 
				{
					0,
					0,
					static_cast<float>(treeTexture.width),
					static_cast<float>(treeTexture.height)
				};
				Vector2 origin = 
				{
					static_cast<float>(treeTexture.width / 2),
					static_cast<float>(treeTexture.height / 2)
				};

				Rectangle dest = 
				{
					origin.x + obstacle.pos.x,
					origin.y,
					obstacle.upperBoxCollider.width,
					obstacle.upperBoxCollider.height
				};

				DrawTexturePro(treeTexture, source, dest, origin, 0, WHITE);

				Vector2 originBottom = 
				{
					static_cast<float>(obstacle.lowerBoxCollider.width / 2),
					static_cast<float>(obstacle.lowerBoxCollider.height / 2)
				};


				Rectangle destBottom = 
				{
					originBottom.x + obstacle.pos.x,
					originBottom.y + obstacle.lowerBoxCollider.y,
					obstacle.lowerBoxCollider.width,
					obstacle.lowerBoxCollider.height
				};

				const int UPSIDE_DOWN_ROTATION = 180;

				DrawTexturePro(treeTexture, source, destBottom, originBottom, UPSIDE_DOWN_ROTATION, WHITE);
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
				const float OBSTACLE_MOVES_PROBABILITY = 0.1f;
				const float GOES_UP_PROBABILITY = 0.5f;

				bool doesObstacleMove = GetRandomValue(1, static_cast<int>(1 / OBSTACLE_MOVES_PROBABILITY)) == 1;
				
				if (doesObstacleMove)
				{
					obstacle.hasVerticalMovement = true;
					bool goesUp = GetRandomValue(1, static_cast<int>(1 / GOES_UP_PROBABILITY)) == 1;
					if ((goesUp && obstacle.verticalSpeed > 0) || (!goesUp && obstacle.verticalSpeed < 0))
						obstacle.verticalSpeed *= -1;
				}
				else
					obstacle.hasVerticalMovement = false;

				float posY = static_cast<float>(GetRandomValue(static_cast<int>(obstacle.obstacleOpeningSize), GetScreenHeight() - static_cast<int>(obstacle.obstacleOpeningSize)));
				//float posY = doesObstacleSpawnUp ? 0 : GetScreenHeight() - obstacle.size.y;
				obstacle.pos = { static_cast<float>(GetScreenWidth()), posY };
				
				obstacle.countedPoint[0] = false;
				obstacle.countedPoint[1] = false;

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
