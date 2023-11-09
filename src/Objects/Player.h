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
				float colliderRadius{ 20 };

				float speed{ 350 };
			};

			void Start();
			void Update();
			void Draw();

			void PlayerTakeDamage();
			Vector2 GetColliderPosition();
			float GetRadius();
		}
	}
}