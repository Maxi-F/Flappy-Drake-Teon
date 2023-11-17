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
				float angle{ 0 };

				Vector2 velocity{ 0, 0 };
				float terminalVelocity = 1500;
				float rotationSpeed = 50;
				float jumpForce = 400;
				float jumpAngle = -15;
				float ceilingBounceForce = 50;
				bool isPullingUp;
				bool canPullUp = true;

				int points = 0;
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