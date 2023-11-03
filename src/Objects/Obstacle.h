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

				float speed;
			};
			void Start(Obstacle& obstacle);
			void Update(Obstacle& obstacle);
			void Draw(Obstacle& obstacle);

		}
	}
}