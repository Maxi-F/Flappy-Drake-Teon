#include "UIManager.h"

#include <string>

#include "Objects/PlayerManager.h"

namespace flappyBird 
{
	namespace game 
	{
		namespace uiManager 
		{
			void init() {};
			void update() {};
			void draw(bool isMultiplayer)
			{
				int MARGIN = 10;
				int SIZE = 32;
				std::string pointsString = "Points: " + std::to_string(playerManager::GetPointsOf(0));

				DrawText(
					pointsString.c_str(),
					MARGIN,
					MARGIN,
					SIZE,
					RED
				);

				if (isMultiplayer)
				{
					std::string pointsTwoString = "Points: " + std::to_string(playerManager::GetPointsOf(1));
					const char* pointsTwoText = pointsTwoString.c_str();

					DrawText(
						pointsTwoText,
						GetScreenWidth() - MeasureText(pointsTwoText, SIZE) - MARGIN,
						MARGIN,
						SIZE,
						GREEN
					);
				}
			};
		}
	}
}
