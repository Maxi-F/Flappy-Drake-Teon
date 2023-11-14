#include "Objects/Player.h"

namespace flappyBird
{
	namespace game
	{
		namespace player
		{

			static Player player;

			static const float GRAVITY = 800.0f;

			void ResetPos();
			void Move();

			void Start()
			{
				ResetPos();
			}

			void Update(bool& shouldReset)
			{
				/*if (IsKeyDown(KEY_S))
					Move(false);
				else if (IsKeyDown(KEY_W))
					Move(true);*/

				if (player.velocity.y + GRAVITY < player.terminalVelocity)
					player.velocity.y += GRAVITY * GetFrameTime();

				if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W) || IsMouseButtonPressed(0))
				{
					player.velocity.y = 0;
					player.velocity.y -= player.jumpForce;
				}

				Move();

				if (player.pos.y + player.size.y / 2 >= GetScreenHeight() - player.size.y / 2)
					shouldReset = true;

				player.isPullingUp = player.velocity.y < 0;
			}

			void Draw()
			{
				Color playerColor = WHITE;
				if (player.isPullingUp)
					playerColor = GREEN;
				else
					playerColor = WHITE;

				DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.size.x), static_cast<int>(player.size.y), playerColor);
#ifdef _DEBUG
				DrawCircleLines(static_cast<int>(player.pos.x + player.size.x / 2), static_cast<int>(player.pos.y + player.size.y / 2), player.colliderRadius, GREEN);
#endif
			}

			void PlayerTakeDamage()
			{
				ResetPos();
			}

			Vector2 GetColliderPosition()
			{
				return { player.pos.x + player.size.x / 2 ,player.pos.y + player.size.y / 2 };
			}

			float GetRadius()
			{
				return player.colliderRadius;
			}

			void ResetPos()
			{
				player.pos = { 50, static_cast<float>(GetScreenHeight()) / 2 };
				player.velocity.y = 0;
			}

			void Move()
			{
				Vector2 playerMinPos = { player.pos.x,0 };
				Vector2 playerMaxPos = { player.pos.x, static_cast<float>(GetScreenHeight()) - player.size.y };
				player.pos = Vector2Clamp(Vector2Add(player.pos, Vector2Scale(player.velocity, GetFrameTime())), playerMinPos, playerMaxPos);
			}
		}
	}
}