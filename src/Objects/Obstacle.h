#pragma once

#include "GameManagement/Utilities.h"

namespace flappyBird
{
	namespace game
	{
		namespace obstacle
		{
			struct Obstacle
			{
				Vector2 pos;
				Vector2 size;

				Rectangle boxCollider;
				
				float speed;
			};
			void Start();
			void Update();
			void Draw();

			void ResetPosition();
			Rectangle GetCollider();

		}
	}
}