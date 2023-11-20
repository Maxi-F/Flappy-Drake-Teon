#pragma once
#include "GameManagement/Utilities.h"


namespace flappyBird
{
	namespace game
	{
		namespace playerManager
		{
			extern const int MAX_PLAYERS_QUANTITY;

			void Start(bool isMultiplayer);
			void Update(bool isMultiplayer, bool& shouldReset);
			void Draw(bool isMultiplayer);
			
			Vector2 GetColliderPositionOf(int playerIndex);
			float GetRadiusOf(int playerIndex);
			
			void AddPointTo(int playerIndex);
			void ResetPoints();
			int GetPointsOf(int playerIndex);

			bool PlayerLost(int playerIndex);
			void SetPlayerLost(int playerIndex);
		}
	}
}