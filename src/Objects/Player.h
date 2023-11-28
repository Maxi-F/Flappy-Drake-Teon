#pragma once
#include "GameManagement/Utilities.h"
#include "GameManagement/SfxManager.h"

namespace flappyBird {
	namespace game {
		namespace player {
			struct Player
			{
				Vector2 pos;
				KeyboardKey upKey;
				utilities::TextureIdentifier idleTexture;
				utilities::TextureIdentifier flyingTexture;
				sfxManager::SfxName wingsSound;

				Vector2 size{ 50,50 };
				float colliderRadius{ 20 };
				float angle{ 0 };

				Vector2 velocity{ 0, 0 };
				float terminalVelocity = 1500;
				float rotationSpeed = 50;
				float jumpForce = 400;
				float jumpAngle = -15;
				float ceilingBounceForce = 50;
				bool isPullingUp;
				bool canPullUp = true;

				int points = 0;
				bool lost = false;
			};

			void updatePlayer(Player& player);
			void drawPlayer(Player player);
			Vector2 GetColliderPosition(Player player);
			float GetRadius(Player player);
			void ResetPos(Player& player);
			void Move(Player& player);
		}
	}
}
