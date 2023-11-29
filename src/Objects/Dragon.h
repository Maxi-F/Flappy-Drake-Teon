#pragma once
#include "GameManagement/Utilities.h"
#include "GameManagement/Timer.h"

namespace flappyBird 
{
	namespace dragon 
	{
		static const int MAX_PLAYERS = 2;

		struct Dragon
		{
			Vector2 pos;
			Vector2 size = { 96, 96 };
			Vector2 collisionSize = { 76, 76 };
			Vector2 offset;
			timer::Timer animationTimer;
			float animationTime;

			float velocity;
			bool countedPoint[MAX_PLAYERS] = { false, false };
		};

		void Start(Dragon& dragon, float offsetX);
		void Update(Dragon& dragon);
		void Draw(Dragon dragon);

		Rectangle GetCollider(Dragon dragon);
	}
}
