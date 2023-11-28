#include "GameManagement/CollisionHandler.h"

#include "GameManagement/Utilities.h"
#include "GameManagement/ObstaclesManager.h"
#include "GameManagement/SfxManager.h"
#include "GameManagement/DragonsManager.h"
#include "GameManagement/GamePlay.h"
#include "Objects/PlayerManager.h"

namespace flappyBird
{
	namespace game
	{
		void CheckFirstPhaseCollisions(bool isMultiplayer);
		void CheckSecondPhaseCollisions(bool isMultiplayer);
		bool CheckCollisionsForPlayer(int playerIndex, int colliderIndex);
		bool CheckDragonPlayerCollision(int playerIndex, int dragonIndex);


		void CheckCollisions(bool isMultiplayer, bool isInSecondPhase)
		{
			if (isInSecondPhase) {
				CheckSecondPhaseCollisions(isMultiplayer);
			}
			else {
				CheckFirstPhaseCollisions(isMultiplayer);
			}
		}

		void CheckSecondPhaseCollisions(bool isMultiplayer) {
			for (int i = 0; i < dragonsManager::DRAGONS_QUANTITY; i++) {
				if (isMultiplayer) {
					for (int j = 0; j < playerManager::MAX_PLAYERS_QUANTITY; j++) {
						if (CheckDragonPlayerCollision(j, i) && !playerManager::PlayerLost(j))
						{
							sfxManager::PlaySound(sfxManager::COLLISION, true);
							playerManager::SetPlayerLost(j);
						}
						else if (!playerManager::PlayerLost(j)) {
							dragonsManager::AddPointToPlayer(j, i);
						}
					}
				}
				else {
					if (CheckDragonPlayerCollision(0, i)) {
						sfxManager::PlaySound(sfxManager::COLLISION, true);
						playerManager::SetPlayerLost(0);
					}
					else {
						dragonsManager::AddPointToPlayer(0, i);
					}
				}
			}
		}

		void CheckFirstPhaseCollisions(bool isMultiplayer) {
			for (int i = 0; i < obstaclesManager::OBSTACLES_QTY; i++)
			{
				if (isMultiplayer) {
					for (int j = 0; j < playerManager::MAX_PLAYERS_QUANTITY; j++) {
						if (CheckCollisionsForPlayer(j, i) && !playerManager::PlayerLost(j))
						{
							sfxManager::PlaySound(sfxManager::COLLISION, true);
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
						sfxManager::PlaySound(sfxManager::COLLISION, true);
						playerManager::SetPlayerLost(0);
					}
					else {
						obstaclesManager::AddPointToPlayer(0, i);
					}
				}
			}
		}

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

		bool CheckDragonPlayerCollision(int playerIndex, int dragonIndex) {
			return CheckCollisionCircleRec(
				playerManager::GetColliderPositionOf(playerIndex),
				playerManager::GetRadiusOf(playerIndex),
				dragonsManager::GetColliderFrom(dragonIndex)
			);
		}
	}
}
