#include "GameManagement/ObstaclesManager.h"

#include <iostream>

namespace flappyBird
{
	namespace game
	{
		namespace obstaclesManager
		{
			static obstacle::Obstacle obstacles[OBSTACLES_QTY];

			static float offset = 0;
			static int obstaclesPassed = 0;
			static const int MAX_OBSTACLES_RESETS = 9;

			void Start()
			{
				offset = static_cast<float>(GetScreenWidth()) / 2;
				obstaclesPassed = 0;
				for (int i = 0; i < OBSTACLES_QTY; i++)
				{
					obstacle::Start(obstacles[i], offset * i);
				}
			}

			void Update()
			{
				for (int i = 0; i < OBSTACLES_QTY; i++)
				{
					obstacle::Update(obstacles[i], obstaclesPassed, MAX_OBSTACLES_RESETS);
				}
			}

			void Draw()
			{
				for (int i = 0; i < OBSTACLES_QTY; i++)
				{
					obstacle::Draw(obstacles[i]);
				}
			}

			void ResetObstacles()
			{
				Start();
			}

			void AddPointToPlayer(int playerIndex, int obstacleIndex) 
			{
				int playerPosX = static_cast<int>(playerManager::GetColliderPositionOf(playerIndex).x + playerManager::GetRadiusOf(playerIndex));
				if (playerPosX >= (obstacles[obstacleIndex].pos.x + obstacles[obstacleIndex].size.x) && !obstacles[obstacleIndex].countedPoint[playerIndex]) 
				{
					playerManager::AddPointTo(playerIndex);
					obstacles[obstacleIndex].countedPoint[playerIndex] = true;
				}
			}

			Rectangle GetObstacleUpperCollider(int obstacleIndex)
			{
				return obstacle::GetUpperCollider(obstacles[obstacleIndex]);
			}
			Rectangle GetObstacleLowerCollider(int obstacleIndex)
			{
				return obstacle::GetLowerCollider(obstacles[obstacleIndex]);
			}
		}
	}
}
