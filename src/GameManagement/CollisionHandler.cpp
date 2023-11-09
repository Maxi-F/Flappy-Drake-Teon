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
			if (CheckCollisionCircleRec(player::GetColliderPosition(), player::GetRadius(), obstacle::GetUpperCollider()) || CheckCollisionCircleRec(player::GetColliderPosition(), player::GetRadius(), obstacle::GetLowerCollider()))
			{
				player::Start();
				obstacle::ResetPosition();
			}
		}
	}
}
