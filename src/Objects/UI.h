#pragma once
#include "GameManagement/Utilities.h"

#include "GameManagement/GameData.h"
#include "Objects/Button.h"

namespace flappyBird
{
	namespace userInterface
	{
		void DrawVersionText();
		void PausePanelDraw(Button& menuButton);
		void GameOverPanelDraw(Button& menuButton, Button& restartButton);
	}
}