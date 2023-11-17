#pragma once
#include "Objects/Obstacle.h"
#include "Objects/Player.h"

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

			bool shouldAddPoint(player::Player player, int obstacleIndex);
			Rectangle GetObstacleUpperCollider(int obstacleIndex);
			Rectangle GetObstacleLowerCollider(int obstacleIndex);
		}
	}
}
