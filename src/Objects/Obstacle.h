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

				Rectangle upperBoxCollider;
				Rectangle lowerBoxCollider;

				const float obstacleOpeningSize = 120;
				
				float speed;
			};
			void Start();
			void Update();
			void Draw();

			void ResetPosition();
			Rectangle GetUpperCollider();
			Rectangle GetLowerCollider();

		}
	}
}