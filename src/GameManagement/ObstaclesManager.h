#pragma once
#include "GameManagement/Utilities.h"

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

			void AddPointToPlayer(int playerIndex, int obstacleIndex);
			Rectangle GetObstacleUpperCollider(int obstacleIndex);
			Rectangle GetObstacleLowerCollider(int obstacleIndex);
		}
	}
}
