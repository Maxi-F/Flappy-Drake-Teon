#include "Button.h"

#include "GameManagement/SfxManager.h"

namespace flappyBird
{
	static const Color PRESSED_BUTTON_DARKGRAY = { 20,20,20,160 };

	void ButtonCollisionCheck(Button& button, Scenes& scene)
	{
		Vector2 mousePos = GetMousePosition();

		if (mousePos.x > button.buttonRect.position.x
			&& mousePos.x <  button.buttonRect.position.x + button.buttonRect.width
			&& mousePos.y > button.buttonRect.position.y
			&& mousePos.y < button.buttonRect.position.y + button.buttonRect.height)
		{
			button.currentTextColor = GRAY;
			button.currentBgColor = DARKGRAY;
			if (IsMouseButtonPressed(0))
			{
				button.wasPressed = true;
			}

			if (IsMouseButtonDown(0) && button.wasPressed)
			{
				button.currentTextColor = DARKGRAY;
				button.currentBgColor = PRESSED_BUTTON_DARKGRAY;
			}

			if (IsMouseButtonReleased(0))
			{
				if (button.wasPressed)
				{
					sfxManager::PlaySound(sfxManager::CLICK, true);
					scene = button.sceneTo;
				}
			}
		}
		else
		{
			button.currentBgColor = button.bgColor;
			button.currentTextColor = button.textColor;
			button.wasPressed = false;
		}
	}

	void ItchPageButtonCollisionCheck(Button& button, const char* link)
	{
		Vector2 mousePos = GetMousePosition();

		if (mousePos.x > button.buttonRect.position.x
			&& mousePos.x <  button.buttonRect.position.x + button.buttonRect.width
			&& mousePos.y > button.buttonRect.position.y
			&& mousePos.y < button.buttonRect.position.y + button.buttonRect.height)
		{
			button.currentTextColor = GRAY;

			if (IsMouseButtonPressed(0))
			{
				button.wasPressed = true;
			}

			if (IsMouseButtonDown(0) && button.wasPressed)
			{
				button.currentTextColor = DARKGRAY;
				button.currentBgColor = PRESSED_BUTTON_DARKGRAY;
			}

			//mouse release 
			if (IsMouseButtonReleased(0))
			{
				if (button.wasPressed)
				{
					OpenURL(link);
					sfxManager::PlaySound(sfxManager::CLICK, true);
				}
			}
		}
		else
		{
			button.currentTextColor = button.textColor;
			button.wasPressed = false;
		}
	}

	void CreditsButtonCollisionCheck(Button& button, bool& creditsScreen)
	{
		Vector2 mousePos = GetMousePosition();

		if (mousePos.x > button.buttonRect.position.x
			&& mousePos.x <  button.buttonRect.position.x + button.buttonRect.width
			&& mousePos.y > button.buttonRect.position.y
			&& mousePos.y < button.buttonRect.position.y + button.buttonRect.height)
		{
			button.currentTextColor = GRAY;
			button.currentBgColor = DARKGRAY;

			if (IsMouseButtonPressed(0))
			{
				button.wasPressed = true;
			}

			if (IsMouseButtonDown(0) && button.wasPressed)
			{
				button.currentTextColor = DARKGRAY;
				button.currentBgColor = PRESSED_BUTTON_DARKGRAY;
			}

			//mouse release 
			if (IsMouseButtonReleased(0))
			{
				if (button.wasPressed)
				{
					if (!creditsScreen)
						creditsScreen = true;
					else
						creditsScreen = false;

					sfxManager::PlaySound(sfxManager::CLICK, true);
				}
			}
		}
		else
		{
			button.currentBgColor = button.bgColor;
			button.currentTextColor = button.textColor;
			button.wasPressed = false;
		}
	}

	void ResetButtonCollisionCheck(Button& button, bool& restartGame)
	{
		Vector2 mousePos = GetMousePosition();

		if (mousePos.x > button.buttonRect.position.x
			&& mousePos.x <  button.buttonRect.position.x + button.buttonRect.width
			&& mousePos.y > button.buttonRect.position.y
			&& mousePos.y < button.buttonRect.position.y + button.buttonRect.height)
		{
			button.currentTextColor = GRAY;
			button.currentBgColor = DARKGRAY;
			if (IsMouseButtonPressed(0))
			{
				button.wasPressed = true;
			}

			if (IsMouseButtonDown(0) && button.wasPressed)
			{
				button.currentTextColor = DARKGRAY;
				button.currentBgColor = PRESSED_BUTTON_DARKGRAY;
			}

			//mouse release 
			if (IsMouseButtonReleased(0))
			{
				if (button.wasPressed)
				{
					sfxManager::PlaySound(sfxManager::CLICK, true);
					restartGame = true;
				}
			}
		}
		else
		{
			button.currentBgColor = button.bgColor;
			button.currentTextColor = button.textColor;
			button.wasPressed = false;
		}
	}

	void ButtonDraw(Button& button, bool drawRectangle)
	{
		if (drawRectangle)
			DrawRectangle(static_cast<int>(button.buttonRect.position.x), static_cast<int>(button.buttonRect.position.y), static_cast<int>(button.buttonRect.width), static_cast<int>(button.buttonRect.height), button.currentBgColor);

		DrawText(button.text, static_cast<int>(button.buttonRect.position.x), static_cast<int>(button.buttonRect.position.y), button.fontSize, button.currentTextColor);
	}
};