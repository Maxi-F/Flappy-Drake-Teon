#include "Objects/Dragon.h"

namespace flappyBird 
{
	namespace dragon 
	{
		void SetStartPosition(Dragon& dragon);
		void ResetPosition(Dragon& dragon);

		void Start(Dragon& dragon, float offsetX) 
		{
			const int MINIMUM_VELOCITY = 500;
			const int MAXIMUM_VELOCITY = 1000;
			const float VELOCITY_ANIMATION_DIVISION_VALUE = 200.0f;

			dragon.offset.x = offsetX;
			dragon.countedPoint[0] = false;
			dragon.countedPoint[1] = false;
			SetStartPosition(dragon);
			dragon.velocity = static_cast<float>(GetRandomValue(MINIMUM_VELOCITY, MAXIMUM_VELOCITY));

			timer::Timer dragonAnimationTimer;
			
			dragon.animationTime = dragon.velocity / VELOCITY_ANIMATION_DIVISION_VALUE;
			timer::StartTimer(&dragonAnimationTimer, dragon.animationTime);
			dragon.animationTimer = dragonAnimationTimer;
		};
		
		void Update(Dragon& dragon) 
		{
			dragon.pos.x -= dragon.velocity * GetFrameTime();

			if (dragon.pos.x + dragon.size.x < 0) {
				ResetPosition(dragon);
			}

			if (timer::TimerDone(dragon.animationTimer)) {
				timer::StartTimer(&dragon.animationTimer, dragon.animationTime);
			}
		};
		
		void Draw(Dragon dragon) 
		{
#ifdef _DEBUG
			Rectangle collider = GetCollider(dragon);

			DrawRectangleLines(
				static_cast<int>(collider.x),
				static_cast<int>(collider.y),
				static_cast<int>(collider.width),
				static_cast<int>(collider.height),
				GREEN
			);
#endif // _DEBUG

			int sheetPlaceMultiplier = 0;
			double elapsedAnimationTime = timer::GetElapsed(dragon.animationTimer);

			if (elapsedAnimationTime >= dragon.animationTime / 4 && elapsedAnimationTime < dragon.animationTime / 2) {
				sheetPlaceMultiplier = 1;
			}
			else if (elapsedAnimationTime >= dragon.animationTime / 2 && elapsedAnimationTime < 3 * dragon.animationTime / 4) {
				sheetPlaceMultiplier = 2;
			}
			else if (elapsedAnimationTime >= 3 * dragon.animationTime && elapsedAnimationTime < dragon.animationTime) {
				sheetPlaceMultiplier = 3;
			}

			Texture dragonTexture = utilities::GetTexture(utilities::TextureIdentifier::BrassDragonSheet);

			Rectangle source = {
				static_cast<float>(sheetPlaceMultiplier * (dragonTexture.width / 4)),
				0,
				static_cast<float>(dragonTexture.width / 4),
				static_cast<float>(dragonTexture.height)
			};

			Rectangle destination = {
				dragon.pos.x,
				dragon.pos.y,
				dragon.size.x,
				dragon.size.y
			};

			DrawTexturePro(
				dragonTexture,
				source,
				destination,
				{ 0, 0 },
				0,
				WHITE
			);
		};

		Rectangle GetCollider(Dragon dragon) 
		{
			const int COLLIDER_MARGIN = 10;
			return {
				dragon.pos.x + COLLIDER_MARGIN,
				dragon.pos.y + COLLIDER_MARGIN,
				dragon.collisionSize.x,
				dragon.collisionSize.y
			};
		};

		void SetStartPosition(Dragon& dragon) 
		{
			float posY = static_cast<float>(
				GetRandomValue(
					0, 
					static_cast<int>(
						GetScreenHeight() - dragon.size.y
					)
				)
			);
			dragon.pos = { static_cast<float>(GetScreenWidth()) + dragon.offset.x, posY };
		}

		void ResetPosition(Dragon& dragon)
		{
			float posY = static_cast<float>(
				GetRandomValue(
					0,
					static_cast<int>(
						GetScreenHeight() - dragon.size.y
					)
				)
			);
			dragon.pos = { static_cast<float>(GetScreenWidth()), posY };

			dragon.countedPoint[0] = false;
			dragon.countedPoint[1] = false;
		}
	}
}