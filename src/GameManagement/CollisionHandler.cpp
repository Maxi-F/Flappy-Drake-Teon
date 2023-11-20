#include "GameManagement/CollisionHandler.h"

#include "GameManagement/Utilities.h"
#include "GameManagement/ObstaclesManager.h"
#include "GameManagement/GamePlay.h"
#include "Objects/PlayerManager.h"

namespace flappyBird
{
	namespace game
	{
		bool CheckCollisionsForPlayer(int playerIndex, int colliderIndex) {
			return CheckCollisionCircleRec(
				playerManager::GetColliderPositionOf(playerIndex),
				playerManager::GetRadiusOf(playerIndex),
				obstaclesManager::GetObstacleUpperCollider(colliderIndex)
			) ||
				CheckCollisionCircleRec(
					playerManager::GetColliderPositionOf(playerIndex),
					playerManager::GetRadiusOf(playerIndex),
					obstaclesManager::GetObstacleLowerCollider(colliderIndex)
				);
		}

		void CheckCollisions(bool isMultiplayer)
		{
			for (int i = 0; i < obstaclesManager::OBSTACLES_QTY; i++)
			{
				if (isMultiplayer) {

				}
				else {
					if (CheckCollisionsForPlayer(0, i))
					{
						SetIsGameOver(true);
					}
					else {
						obstaclesManager::AddPointToPlayer(0, i);
					}
				}
			}
		}
	}
}
