#include "Objects/Dragon.h"

namespace flappyBird {
	namespace dragon {
		void SetStartPosition(Dragon& dragon);
		void ResetPosition(Dragon& dragon);

		void Start(Dragon& dragon, float offsetX) 
		{
			dragon.offset.x = offsetX;
			dragon.countedPoint[0] = false;
			dragon.countedPoint[1] = false;
			SetStartPosition(dragon);
			dragon.velocity = static_cast<float>(GetRandomValue(500, 1000));
		};
		
		void Update(Dragon& dragon) 
		{
			dragon.pos.x -= dragon.velocity * GetFrameTime();

			if (dragon.pos.x + dragon.size.x < 0) {
				ResetPosition(dragon);
			}
		};
		
		void Draw(Dragon dragon) 
		{
			DrawRectangleRec(
				GetCollider(dragon),
				RED
			);
		};

		Rectangle GetCollider(Dragon dragon) 
		{
			return {
				dragon.pos.x,
				dragon.pos.y,
				dragon.size.x,
				dragon.size.y
			};
		};

		void SetStartPosition(Dragon& dragon) 
		{
			float posY = static_cast<float>(
				GetRandomValue(
					static_cast<int>(dragon.size.y), 
					static_cast<int>(GetScreenHeight()
					- dragon.size.y)
				));
			dragon.pos = { static_cast<float>(GetScreenWidth()) + dragon.offset.x, posY };
		}

		void ResetPosition(Dragon& dragon)
		{
			float posY = static_cast<float>(GetRandomValue(
				static_cast<int>(dragon.size.y),
				static_cast<int>(GetScreenHeight()
					- dragon.size.y)
			));
			dragon.pos = { static_cast<float>(GetScreenWidth()), posY };

			dragon.countedPoint[0] = false;
			dragon.countedPoint[1] = false;
		}
	}
}