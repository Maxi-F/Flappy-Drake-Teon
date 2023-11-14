#pragma once
#include "GameManagement/Utilities.h"


namespace flappyBird
{
	namespace game
	{
		namespace player
		{
			

			void Start();
			void Update(bool& shouldReset);
			void Draw();

			void PlayerTakeDamage();
			Vector2 GetColliderPosition();
			float GetRadius();
		}
	}
}