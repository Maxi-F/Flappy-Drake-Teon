#include "GameManagement/UI.h"

#include "GameManagement/Utilities.h"

namespace flappyBird
{
	namespace userInterface
	{
		static const int SPACING = 5;
		static float fontSize = 20;
		void DrawVersionText()
		{
			const char* versionText = "0.1";
			Vector2 textSize = MeasureTextEx(GetFontDefault(), versionText, fontSize, SPACING);
			DrawText(versionText, GetScreenWidth() - static_cast<int>(textSize.x), GetScreenHeight() - static_cast<int>(textSize.y), static_cast<int>(fontSize), WHITE);
		}
	}
}