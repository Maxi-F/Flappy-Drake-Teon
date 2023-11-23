#pragma once

#include "GameManagement/Utilities.h"

namespace flappyBird
{
	namespace game
	{
		namespace obstacle
		{
			static const int MAX_PLAYERS = 2;
			struct Obstacle
			{
				Vector2 pos;
				Vector2 size;
				Vector2 offset;

				Rectangle upperBoxCollider;
				Rectangle lowerBoxCollider;

				bool hasVerticalMovement = false;
				bool countedPoint[MAX_PLAYERS] = { false, false };
				float verticalSpeed = 200;
				const float obstacleOpeningSize = 150;
				
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
