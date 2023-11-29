#pragma once
#include "GameManagement/Utilities.h"
#include "GameManagement/SfxManager.h"

namespace flappyBird 
{
	namespace game 
	{
		namespace player 
		{
			static const int PLAYER_SIZE = 50;
			static const float PLAYER_COLLIDER_RADIUS = 20.0f;
			static const float PLAYER_TERMINAL_VELOCITY = 1500.0f;
			static const float PLAYER_JUMP_VELOCITY = 400.0f;
			static const float PLAYER_JUMP_SPRITE_ANGLE = -15.0f;
			static const float PLAYER_ROTATION_SPEED = 50.0f;
			static const float CEILING_BOUNCE_FORCE = 50.0f;

			struct Player
			{
				Vector2 pos;
				KeyboardKey upKey;
				utilities::TextureIdentifier idleTexture;
				utilities::TextureIdentifier flyingTexture;
				sfxManager::SfxName wingsSound;
				
				Vector2 size = { PLAYER_SIZE, PLAYER_SIZE };
				float colliderRadius = PLAYER_COLLIDER_RADIUS;
				float angle = 0;

				Vector2 velocity = { 0, 0 };
				float terminalVelocity = PLAYER_TERMINAL_VELOCITY;
				float rotationSpeed = PLAYER_ROTATION_SPEED;
				float jumpForce = PLAYER_JUMP_VELOCITY;
				float jumpAngle = PLAYER_JUMP_SPRITE_ANGLE;
				float ceilingBounceForce = CEILING_BOUNCE_FORCE;
				bool isPullingUp;
				bool canPullUp = true;

				int points = 0;
				bool lost = false;
			};

			void UpdatePlayer(Player& player);
			void DrawPlayer(Player player);
			Vector2 GetColliderPosition(Player player);
			float GetRadius(Player player);
			void ResetPos(Player& player);
			void Move(Player& player);
		}
	}
}
