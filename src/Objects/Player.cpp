#include "Objects/Player.h"

namespace flappyBird {
	namespace game {
		namespace player {
			static const float GRAVITY = 1000.0f;

			void updatePlayer(Player& player) {
				player.velocity.y += GRAVITY * GetFrameTime();

				if (player.pos.y == 0)
				{
					player.canPullUp = false;
					player.velocity.y = player.ceilingBounceForce;
				}
				else
					player.canPullUp = true;


				if (IsKeyPressed(player.upKey))
				{
					if (player.canPullUp)
					{
						player.velocity.y = 0;
						player.velocity.y -= player.jumpForce;
						player.angle = player.jumpAngle;
					}
				}


				Move(player);

				if (player.pos.y + player.size.y / 2 >= GetScreenHeight() - player.size.y / 2)
					player.lost = true;

				player.isPullingUp = player.velocity.y < 0;

				if (!player.isPullingUp)
					player.angle += player.rotationSpeed * GetFrameTime();
			}

			void drawPlayer(Player player) {
				if (player.lost) return;
				Texture playerTextureToDraw = utilities::GetTexture(player.idleTexture);
				if (player.isPullingUp)
					playerTextureToDraw = utilities::GetTexture(player.flyingTexture);

				DrawTexturePro(playerTextureToDraw, { 0,0,64,64 }, { player.pos.x + player.size.x / 2 , player.pos.y + player.size.y / 2, player.size.x, player.size.y }, { player.size.x / 2, player.size.y / 2 }, player.angle, WHITE);
#ifdef _DEBUG
				DrawCircleLines(static_cast<int>(player.pos.x + player.size.x / 2), static_cast<int>(player.pos.y + player.size.y / 2), player.colliderRadius, GREEN);
#endif
			}

			Vector2 GetColliderPosition(Player player)
			{
				return { player.pos.x + player.size.x / 2 ,player.pos.y + player.size.y / 2 };
			}

			float GetRadius(Player player)
			{
				return player.colliderRadius;
			}

			void ResetPos(Player& player)
			{
				player.pos = { 50, static_cast<float>(GetScreenHeight()) / 2 };
				player.velocity.y = 0;
				player.angle = 0;
			}

			void Move(Player& player)
			{
				Vector2 playerMinPos = { player.pos.x,0 };
				Vector2 playerMaxPos = { player.pos.x, static_cast<float>(GetScreenHeight()) - player.size.y };
				player.pos = Vector2Clamp(Vector2Add(player.pos, Vector2Scale(player.velocity, GetFrameTime())), playerMinPos, playerMaxPos);
			}
		}
	}
}