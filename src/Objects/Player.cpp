#include "Objects/Player.h"

namespace flappyBird
{
	namespace game
	{
		namespace player
		{
			void Move(Player& player, bool goesUp);

			void Start(Player& player)
			{
				player.pos = { 50, static_cast<float>(GetScreenHeight()) / 2 };
			}

			void Update(Player& player)
			{
				if (IsKeyDown(KEY_S))
					Move(player, false);
				else if (IsKeyDown(KEY_W))
					Move(player, true);
			}


			void Draw(Player& player)
			{
				DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.size.x), static_cast<int>(player.size.y), WHITE);
			}

			void Move(Player& player, bool goesUp)
			{
				if (goesUp)
					player.pos.y -= player.speed * GetFrameTime();
				else
					player.pos.y += player.speed * GetFrameTime();
			}
		}
	}
}