#include "GameManagement/CollisionHandler.h"

#include "GameManagement/Utilities.h"

#include "GameManagement/ObstaclesManager.h"
#include "Objects/Player.h"

namespace flappyBird
{
	namespace game
	{
		void CheckCollisions()
		{
			for (int i = 0; i < obstaclesManager::OBSTACLES_QTY; i++)
			{
				if (CheckCollisionCircleRec(player::GetColliderPosition(), player::GetRadius(), obstaclesManager::GetObstacleUpperCollider(i)) || CheckCollisionCircleRec(player::GetColliderPosition(), player::GetRadius(), obstaclesManager::GetObstacleLowerCollider(i)))
				{
					player::Start();
					obstaclesManager::ResetObstacles();
				}
				else {
					obstaclesManager::AddPointToPlayer(i);
				}
			}
		}
	}
}
