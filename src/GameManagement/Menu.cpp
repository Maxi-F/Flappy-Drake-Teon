#include "GameManagement/Menu.h"

#include "Objects/Button.h"
#include "Objects/UI.h"
//#include "GameManagement/AudioManager.h"
#include <iostream>

namespace flappyBird
{
	struct MenuData
	{
		const char* title = "Flappy Drake";
		int titleSize = 80;
		int titleLimitSpacing = 70;

		const char* createdCredits = "Created By Nico Laure";
		const char* extensionCredits = "Extended by Maxi Feldman";
		int creditsSize = 30;

		static const int buttonsQty = 4;
		Button scenesButtons[buttonsQty] = {
			{{0,0}, Scenes::Game, "Singleplayer"},
			{{0,0}, Scenes::MultiplayerGame, "Multiplayer"},
			{{0,0}, Scenes::Menu,"Credits"},
			{{0,0}, Scenes::GameQuit,"Exit Game"}

		};

		Button creatorItchPageButton = { {0,0}, Scenes::Menu, createdCredits, creditsSize };
		Button ExtensionItchPageButton = { {0,0}, Scenes::Menu, extensionCredits, creditsSize };

		bool showCreditsScreen = false;
		Button closeCredits = { {0,0}, Scenes::Menu,"Close Credits" };
	};

	static MenuData menuData;

	void MenuStart();
	void MenuUpdate(Scenes& scene);
	void MenuDraw();

	void MenuScene(bool isNewScene, Scenes& actualScene)
	{
		if (isNewScene)
			MenuStart();

		MenuUpdate(actualScene);
		MenuDraw();
	}
	void MenuStart()
	{
		Vector2 textSize = { 0,0 };

		//PlayMusicStream(GetMusic(MusicIdentifier::MenuMusic));
		float windowLimitSpacing = 20;
		textSize = MeasureTextEx(
			GetFontDefault(),
			menuData.creatorItchPageButton.text,
			static_cast<float>(menuData.creatorItchPageButton.fontSize),
			menuData.creatorItchPageButton.fontSize * 0.1f
		);

		menuData.creatorItchPageButton.buttonRect = {
			{
				static_cast<float>(GetScreenWidth()) - MeasureText(menuData.createdCredits, menuData.creditsSize) - windowLimitSpacing,
				static_cast<float>(GetScreenHeight()) - menuData.creditsSize * 2 - windowLimitSpacing},
				textSize.y,
				textSize.x
		};

		textSize = MeasureTextEx(
			GetFontDefault(),
			menuData.ExtensionItchPageButton.text,
			static_cast<float>(menuData.ExtensionItchPageButton.fontSize),
			menuData.ExtensionItchPageButton.fontSize * 0.1f
		);

		menuData.ExtensionItchPageButton.buttonRect = {
			{
				static_cast<float>(GetScreenWidth()) - MeasureText(menuData.extensionCredits, menuData.creditsSize) - windowLimitSpacing,
				static_cast<float>(GetScreenHeight()) - menuData.creditsSize - windowLimitSpacing
			},
			textSize.y,
			textSize.x
		};

		for (int i = 0; i < menuData.buttonsQty; i++)
		{
			textSize = MeasureTextEx(GetFontDefault(), menuData.scenesButtons[i].text, static_cast<float>(menuData.scenesButtons[i].fontSize), menuData.scenesButtons[i].fontSize * 0.1f);
			menuData.scenesButtons[i].buttonRect = { {windowLimitSpacing, static_cast<float>(GetScreenHeight()) / 3 + i * menuData.scenesButtons[i].fontSize * 1.6f}, textSize.y, textSize.x };
		}
	}
	void MenuUpdate(Scenes& scene)
	{
		//UpdateMusicStream(GetMusic(MusicIdentifier::MenuMusic));
		if (!menuData.showCreditsScreen)
		{
			ItchPageButtonCollisionCheck(menuData.creatorItchPageButton, "https://nico-drake.itch.io/");
			ItchPageButtonCollisionCheck(menuData.ExtensionItchPageButton, "https://teonnn.itch.io/");
			for (Button& button : menuData.scenesButtons)
			{
				if (button.sceneTo == Scenes::Menu)
					CreditsButtonCollisionCheck(button, menuData.showCreditsScreen);

				ButtonCollisionCheck(button, scene);
			}
		}
		else
		{
			CreditsButtonCollisionCheck(menuData.closeCredits, menuData.showCreditsScreen);
		}
	}

	void MenuDraw()
	{
		float windowLimitSpacing = 20;

		BeginDrawing();

		if (!menuData.showCreditsScreen)
		{
			ClearBackground(BLACK);
			DrawText(menuData.title, GetScreenWidth() / 2 - MeasureText(menuData.title, menuData.titleSize) / 2, static_cast<int>(windowLimitSpacing), menuData.titleSize, WHITE);
			DrawText(
				menuData.createdCredits, GetScreenWidth() - MeasureText(menuData.createdCredits, menuData.creditsSize) - static_cast<int>(windowLimitSpacing),
				GetScreenHeight() - menuData.creditsSize * 2 - static_cast<int>(windowLimitSpacing),
				menuData.creditsSize,
				menuData.creatorItchPageButton.currentTextColor
			);

			DrawText(
				menuData.extensionCredits, GetScreenWidth() - MeasureText(menuData.extensionCredits, menuData.creditsSize) - static_cast<int>(windowLimitSpacing),
				GetScreenHeight() - menuData.creditsSize - static_cast<int>(windowLimitSpacing),
				menuData.creditsSize,
				menuData.ExtensionItchPageButton.currentTextColor
			);

			for (Button& button : menuData.scenesButtons)
			{
				ButtonDraw(button, false);
			}
			userInterface::DrawVersionText();
		}
		else
		{
			Color panelColor = { 50,50,50,255 };
			DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), panelColor);

			int creditsSize = 25;
			int creditsHorizontalDisplacement = 20;
			int creditsSpacing = 70;
			//const char* santiText = "Player And Asteroids by Santiago Garrido instagram: @tains_art";
			const char* nicoText = "Programming made by Nicolas Laure: https://nico-drake.itch.io";
			const char* maxiText = "Extension made by Maxi Feldman: https://teonnn.itch.io";
			const char* backGroundText = "Background by Eder Munizz: https://edermunizz.itch.io/free-pixel-art-forest";
			const char* dragonsText = "Dragon sprites by DeepDiveGameStudio https://deepdivegamestudio.itch.io/dragon-asset-pack";

			//DrawText(santiText, creditsHorizontalDisplacement, GetScreenHeight() / 2 - creditsSpacing * 2, creditsSize, WHITE);
			DrawText(nicoText, creditsHorizontalDisplacement, GetScreenHeight() / 2 - creditsSpacing * 3, creditsSize, WHITE);
			DrawText(maxiText, creditsHorizontalDisplacement, GetScreenHeight() / 2 - creditsSpacing * 2, creditsSize, WHITE);
			DrawText(dragonsText, creditsHorizontalDisplacement, GetScreenHeight() / 2 - creditsSpacing, creditsSize, WHITE);
			DrawText(backGroundText, creditsHorizontalDisplacement, GetScreenHeight() / 2, creditsSize, WHITE);
			const char* title = "Credits";
			int titleSize = 70;
			int verticalDisplacement = 20;
			DrawText(title, GetScreenWidth() / 2 - MeasureText(title, titleSize) / 2, verticalDisplacement, titleSize, WHITE);


			int buttonSpacing = 120;
			menuData.closeCredits.buttonRect.position = { static_cast<float>(GetScreenWidth()) / 2 - static_cast<float>(MeasureText(menuData.closeCredits.text, menuData.closeCredits.fontSize)) / 2, static_cast<float>(GetScreenHeight()) - buttonSpacing };
			menuData.closeCredits.buttonRect.width = static_cast<float>(MeasureText(menuData.closeCredits.text, menuData.closeCredits.fontSize));
			menuData.closeCredits.buttonRect.height = static_cast<float>(menuData.closeCredits.fontSize);
			menuData.closeCredits.bgColor = DARKGRAY;
			ButtonDraw(menuData.closeCredits, true);
		}
		EndDrawing();
	}
};