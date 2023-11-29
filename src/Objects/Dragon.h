#pragma once
#include "GameManagement/Utilities.h"
#include "GameManagement/Timer.h"

namespace flappyBird 
{
	namespace dragon 
	{
		static const int MAX_PLAYERS = 2;
		static const int DRAGON_SIZE = 96;
		static const int DRAGON_COLLISION_SIZE = 76;

		struct Dragon
		{
			Vector2 pos;
			Vector2 size = { DRAGON_SIZE, DRAGON_SIZE };
			Vector2 collisionSize = { DRAGON_COLLISION_SIZE, DRAGON_COLLISION_SIZE };
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
