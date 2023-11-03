#pragma once
#include "GameManagement/Utilities.h"


namespace flappyBird
{
	namespace game
	{
		namespace player
		{
			struct Player
			{
				Vector2 pos;
				Vector2 size{ 50,50 };

				float speed{ 350 };
			};

			void Start(Player& player);
			void Update(Player& player);
			void Draw(Player& player);
		}
	}
}