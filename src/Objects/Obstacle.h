#pragma once

#include "GameManagement/Utilities.h"

namespace flappyBird
{
	namespace game
	{
		namespace obstacle
		{
			static const int MAX_PLAYERS = 2;
			static const float OBSTACLE_VERTICAL_SPEED = 200.0f;
			static const float OBSTACLE_OPENING_SIZE = 150.0f;

			struct Obstacle
			{
				Vector2 pos;
				Vector2 size;
				Vector2 offset;

				Rectangle upperBoxCollider;
				Rectangle lowerBoxCollider;

				bool hasVerticalMovement = false;
				bool countedPoint[MAX_PLAYERS] = { false, false };
				float verticalSpeed = OBSTACLE_VERTICAL_SPEED;
				const float obstacleOpeningSize = OBSTACLE_OPENING_SIZE;
				
				float speed;
			};
			void Start(Obstacle& obstacle,float offsetX);
			void Update(Obstacle& obstacle, int& obstaclesPassed, int maxObstacles);
			void Draw(Obstacle& obstacle);

			void ResetPosition(Obstacle& obstacle);
			Rectangle GetUpperCollider(Obstacle& obstacle);
			Rectangle GetLowerCollider(Obstacle& obstacle);
		}
	}
}
