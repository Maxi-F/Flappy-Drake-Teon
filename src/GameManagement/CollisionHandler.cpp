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
					for (int j = 0; j < playerManager::MAX_PLAYERS_QUANTITY; j++) {
						if (CheckCollisionsForPlayer(j, i) && !playerManager::PlayerLost(j))
						{
							playerManager::SetPlayerLost(j);
						}
						else if (!playerManager::PlayerLost(j)) {
							obstaclesManager::AddPointToPlayer(j, i);
						}
					}
				}
				else {
					if (CheckCollisionsForPlayer(0, i))
					{
						playerManager::SetPlayerLost(0);
					}
					else {
						obstaclesManager::AddPointToPlayer(0, i);
					}
				}
			}
		}
	}
}
