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
				players[0].idleTexture = utilities::TextureIdentifier::PlayerIdle;
				players[0].flyingTexture = utilities::TextureIdentifier::PlayerFlying;

				if (isMultiplayer) {
					player::ResetPos(players[1]);
					players[1].upKey = KEY_W;
					players[1].points = 0;
					players[1].lost = false;

					players[1].idleTexture = utilities::TextureIdentifier::PlayerTwoIdle;
					players[1].flyingTexture = utilities::TextureIdentifier::PlayerTwoFlying;
				}
				else {
					players[1].lost = true;
				}
			}

			void Update(bool isMultiplayer, bool& shouldReset, bool& isPhasingToSecondPhase)
			{
				if (isMultiplayer) {
					for (int i = 0; i < MAX_PLAYERS_QUANTITY; i++) {
						player::updatePlayer(players[i]);
					}
				}
				else {
					player::updatePlayer(players[0]);
				}
				const int POINTS_TO_SECOND_PHASE = 10;

				if (AnyPlayerHasMoreThan(POINTS_TO_SECOND_PHASE)) {
					isPhasingToSecondPhase = true;
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

			bool AnyPlayerHasMoreThan(int points) {
				for (int i = 0; i < MAX_PLAYERS_QUANTITY; i++) {
					if (players[i].points > points) {
						return true;
					}
				}
				return false;
			}

			bool ShouldReset() {
				for (int i = 0; i < MAX_PLAYERS_QUANTITY; i++) {
					if (!players[i].lost) {
						return false;
					}
				}

				return true;
			}

			bool PlayerLost(int playerIndex) {
				return players[playerIndex].lost;
			}

			void SetPlayerLost(int playerIndex) {
				players[playerIndex].lost = true;
			}
		}
	}
}