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

				Vector2 velocity{ 0, 0 };
				float terminalVelocity = 1500;
				float jumpForce = 400;
				//float speed{ 350 };
				bool isPullingUp;
			};

			void Start();
			void Update(bool& shouldReset);
			void Draw();

			void PlayerTakeDamage();
			Vector2 GetColliderPosition();
			float GetRadius();
		}
	}
}