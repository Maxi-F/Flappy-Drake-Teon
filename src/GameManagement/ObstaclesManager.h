#pragma once
#include "Objects/Obstacle.h"

namespace flappyBird
{
	namespace game
	{
		namespace obstaclesManager
		{
			void Start();
			void Update();
			void Draw();
			void ResetObstacles();

			const int OBSTACLES_QTY = 2;

			Rectangle GetObstacleUpperCollider(int obstacleIndex);
			Rectangle GetObstacleLowerCollider(int obstacleIndex);
		}
	}
}
