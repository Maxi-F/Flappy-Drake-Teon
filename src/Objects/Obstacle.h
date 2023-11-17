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
				Vector2 offset;

				Rectangle upperBoxCollider;
				Rectangle lowerBoxCollider;

				bool hasVerticalMovement = false;
				bool countedPoint = false;
				float verticalSpeed = 200;
				const float obstacleOpeningSize = 120;
				
				float speed;
			};
			void Start(Obstacle& obstacle,float offsetX);
			void Update(Obstacle& obstacle);
			void Draw(Obstacle& obstacle);

			void ResetPosition(Obstacle& obstacle);
			Rectangle GetUpperCollider(Obstacle& obstacle);
			Rectangle GetLowerCollider(Obstacle& obstacle);
		}
	}
}