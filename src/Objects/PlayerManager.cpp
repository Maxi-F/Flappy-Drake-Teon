#include "Objects/PlayerManager.h"

#include "GameManagement/TexturesManager.h"
#include "Objects/Player.h"

namespace flappyBird
{
	namespace game
	{
		namespace playerManager
		{
			extern const int MAX_PLAYERS_QUANTITY = 2;
			static player::Player players[MAX_PLAYERS_QUANTITY];

			bool ShouldReset();

			void Start(bool isMultiplayer)
			{
				player::ResetPos(players[0]);
				players[0].upKey = KEY_UP;
				players[0].points = 0;
				players[0].lost = false;

				if (isMultiplayer) {
					player::ResetPos(players[1]);
					players[0].upKey = KEY_W;
					players[0].points = 0;

					players[1].lost = false;
				}
				else {
					players[1].lost = true;
				}
			}

			void Update(bool isMultiplayer, bool& shouldReset)
			{
				if (isMultiplayer) {
					for (int i = 0; i < MAX_PLAYERS_QUANTITY; i++) {
						player::updatePlayer(players[i]);
					}
				}
				else {
					player::updatePlayer(players[0]);
				}

				shouldReset = ShouldReset();
			}

			void Draw(bool isMultiplayer)
			{
				if (isMultiplayer) {
					for (int i = 0; i < MAX_PLAYERS_QUANTITY; i++) {
						player::drawPlayer(players[i]);
					}
				}
				else {
					player::drawPlayer(players[0]);
				}
			}
			
			Vector2 GetColliderPositionOf(int playerIndex) {
				return player::GetColliderPosition(players[playerIndex]);
			}

			float GetRadiusOf(int playerIndex) {
				return player::GetRadius(players[playerIndex]);
			}

			void AddPointTo(int playerIndex) {
				players[playerIndex].points++;
			}

			void ResetPoints() {
				for (int i = 0; i < MAX_PLAYERS_QUANTITY; i++) {
					players[i].points = 0;
				}
			}

			int GetPointsOf(int playerIndex) {
				return players[playerIndex].points;
			}

			bool ShouldReset() {
				for (int i = 0; i < MAX_PLAYERS_QUANTITY; i++) {
					if (!players[i].lost) {
						return false;
					}
				}

				return true;
			}
		}
	}
}