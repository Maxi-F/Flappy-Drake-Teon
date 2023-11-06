#include "Objects/Player.h"

namespace flappyBird
{
	namespace game
	{
		namespace player
		{

			static Player player;

			void ResetPos();
			void Move(bool goesUp);

			void Start()
			{
				ResetPos();
			}

			void Update()
			{
				if (IsKeyDown(KEY_S))
					Move(false);
				else if (IsKeyDown(KEY_W))
					Move(true);
			}

			void Draw()
			{
				DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.size.x), static_cast<int>(player.size.y), WHITE);
#ifdef _DEBUG
				DrawCircleLines(static_cast<int>(player.pos.x + player.size.x / 2), static_cast<int>(player.pos.y + player.size.y / 2), player.colliderRadius, GREEN);
#endif
			}

			void PlayerTakeDamage()
			{
				ResetPos();
			}

			Vector2 GetPosition()
			{
				return player.pos;
			}

			float GetRadius()
			{
				return player.colliderRadius;
			}

			void ResetPos()
			{
				player.pos = { 50, static_cast<float>(GetScreenHeight()) / 2 };
			}

			void Move(bool goesUp)
			{
				if (goesUp)
					player.pos.y -= player.speed * GetFrameTime();
				else
					player.pos.y += player.speed * GetFrameTime();
			}
		}
	}
}