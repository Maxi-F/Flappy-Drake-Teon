#include "Objects/BackGround.h"

#include "Objects/Layer.h"

namespace flappyBird
{
	namespace game
	{
		namespace backGround
		{
			static const float BACKGROUND_SPEED = 100;
			void Start()
			{
				layer::SetAllLayers();
			}

			void Update()
			{
				layer::UpdateAllLayers(BACKGROUND_SPEED);
			}

			void Draw()
			{
				layer::DrawAllLayers();
			}

		}
	}
}

