#include "GameManagement/CollisionHandler.h"

#include "GameManagement/Utilities.h"

#include "Objects/Obstacle.h"
#include "Objects/Player.h"

namespace flappyBird
{
	namespace game
	{
		void CheckCollisions()
		{
			if (CheckCollisionCircleRec(player::GetPosition(), player::GetRadius(), obstacle::GetCollider()))
			{
				player::Start();
				obstacle::ResetPosition();
			}
		}
	}
}
