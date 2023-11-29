#include "GameManagement/DragonsManager.h"

#include "Objects/Dragon.h"
#include "Objects/PlayerManager.h"

namespace flappyBird 
{
	namespace game 
	{
		namespace dragonsManager 
		{
			extern const int DRAGONS_QUANTITY = 8;

			static dragon::Dragon dragons[DRAGONS_QUANTITY];
		
			void Start() 
			{
				float offset = static_cast<float>(GetScreenWidth()) / 2;

				for (int i = 0; i < DRAGONS_QUANTITY; i++) 
				{
					dragon::Start(dragons[i], offset + GetRandomValue(0, 100) * i);
				}
			};

			void Update() 
			{
				for (int i = 0; i < DRAGONS_QUANTITY; i++) 
				{
					dragon::Update(dragons[i]);
				}
			};
		
			void Draw()
			{
				for (int i = 0; i < DRAGONS_QUANTITY; i++) 
				{
					dragon::Draw(dragons[i]);
				}
			};

			Rectangle GetColliderFrom(int index) 
			{
				return dragon::GetCollider(dragons[index]);
			}

			void AddPointToPlayer(int playerIndex, int dragonIndex) 
			{
				int playerPosX = static_cast<int>(playerManager::GetColliderPositionOf(playerIndex).x + playerManager::GetRadiusOf(playerIndex));
				if (playerPosX >= (dragons[dragonIndex].pos.x + dragons[dragonIndex].size.x) && !dragons[dragonIndex].countedPoint[playerIndex])
				{
					playerManager::AddPointTo(playerIndex);
					dragons[dragonIndex].countedPoint[playerIndex] = true;
				}
			}
		}
	}
}
