#include "Objects/UI.h"

#include <string>

#include "GameManagement/Utilities.h"
#include "Objects/Player.h"

using namespace std;

namespace flappyBird
{
	namespace userInterface
	{
		static int titleWindowLimitSpacing = 60;
		static int pointsWindowLimitSpacing = 20;
		static int pressKeyWindowLimitSpacing = 120;
		static int wordsSpacing = 40;

		static const int SPACING = 5;
		static float fontSize = 25;
		void DrawVersionText()
		{
			const char* versionText = "0.2";
			Vector2 textSize = MeasureTextEx(GetFontDefault(), versionText, fontSize, SPACING);
			DrawText(versionText, GetScreenWidth() - static_cast<int>(textSize.x), 0, static_cast<int>(fontSize), WHITE);
		}

		void PausePanelDraw(Button& menuButton)
		{
			Color panelColor = { 60,60,60,255 };
			DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), panelColor);
			const char* pauseTitle = "Game is Paused";
			int titleSize = static_cast<int>(120);

			const char* resumeText = "Press Middle Click to go resume Game";
			int resumeTextSize = static_cast <int>(60);

			int buttonsSpacing = 30;

			menuButton.buttonRect.position = { static_cast<float>(GetScreenWidth()) / 2 - MeasureText(menuButton.text, menuButton.fontSize) / 2 , static_cast<float>(GetScreenHeight()) / 2 + buttonsSpacing };
			menuButton.buttonRect.width = static_cast<float>(MeasureText(menuButton.text, menuButton.fontSize));
			menuButton.buttonRect.height = static_cast<float>(menuButton.fontSize);
			menuButton.bgColor = GRAY;

			ButtonDraw(menuButton, true);

			DrawText(pauseTitle, GetScreenWidth() / 2 - MeasureText(pauseTitle, titleSize) / 2, titleWindowLimitSpacing, titleSize, WHITE);
			DrawText(resumeText, GetScreenWidth() / 2 - MeasureText(resumeText, resumeTextSize) / 2, GetScreenHeight() / 2 - pressKeyWindowLimitSpacing, resumeTextSize, WHITE);
		}

		void GameOverPanelDraw(Button& menuButton, Button& restartButton)
		{
			const char* title = "Game Over";

			std::string pointsString = "Points: " + std::to_string(game::player::GetPoints());
			const char* pointsText = pointsString.c_str();

			int titleSize = 130;
			int pointsSize = 70;

			int buttonsSpacing = 50;

			menuButton.buttonRect.position = { static_cast<float>(GetScreenWidth()) / 2 - MeasureText(menuButton.text, menuButton.fontSize) / 2 , static_cast<float>(GetScreenHeight()) / 2 + buttonsSpacing };
			menuButton.buttonRect.width = static_cast<float>(MeasureText(menuButton.text, menuButton.fontSize));
			menuButton.buttonRect.height = static_cast<float>(menuButton.fontSize);
			menuButton.bgColor = DARKGRAY;

			ButtonDraw(menuButton, true);

			restartButton.buttonRect.position = { static_cast<float>(GetScreenWidth()) / 2 - MeasureText(restartButton.text, restartButton.fontSize) / 2, static_cast<float>(GetScreenHeight()) / 2 - buttonsSpacing };
			restartButton.buttonRect.width = static_cast<float>(MeasureText(restartButton.text, restartButton.fontSize));
			restartButton.buttonRect.height = static_cast<float>(restartButton.fontSize);
			restartButton.bgColor = DARKGRAY;

			ButtonDraw(restartButton, true);

			DrawText(title, GetScreenWidth() / 2 - MeasureText(title, titleSize) / 2, titleWindowLimitSpacing, titleSize, WHITE);
			DrawText(
				pointsText,
				GetScreenWidth() / 2 - MeasureText(pointsText, pointsSize) / 2,
				titleWindowLimitSpacing + titleSize + pointsWindowLimitSpacing,
				pointsSize,
				RED
			);
		}
	}
}
