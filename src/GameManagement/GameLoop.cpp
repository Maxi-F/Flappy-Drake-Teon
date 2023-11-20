#include "GameManagement/GameLoop.h"

#include <iostream>
#include "raylib/raylib.h"

#include "GameManagement/Gameplay.h"
#include "GameManagement/Menu.h"
#include "GameManagement/Utilities.h"
#include "GameManagement/SceneManager.h"

namespace flappyBird
{

	void Initialize();

	static SceneManager sceneManager;

	void Initialize();
	void GameLoop();

	void RunGame()
	{
		Initialize();
		GameLoop();
		//CloseAudioDevice();
		CloseWindow();
	}

	void Initialize()
	{
		InitWindow(1280, 720, "Flappy Drake");
		//InitAudioDevice();
		SetExitKey(NULL);
		sceneManager.prevScene = Scenes::GameQuit;
		utilities::SetTextures();
		//SetSounds();
		SetRandomSeed(static_cast<unsigned int>(time(nullptr)));
	}

	void GameLoop()
	{
		do
		{
			sceneManager.enteredNewScene = sceneManager.currentScene != sceneManager.prevScene;
			sceneManager.prevScene = sceneManager.currentScene;

			switch (sceneManager.currentScene)
			{
			case Scenes::GameQuit:
				break;
			case Scenes::GameOver:
				break;
			case Scenes::Menu:
				MenuScene(sceneManager.enteredNewScene, sceneManager.currentScene);
				break;
			case Scenes::Game:
				game::GamePlayLoop(sceneManager.enteredNewScene, sceneManager.currentScene);
				break;
			default:
				break;
			}
		} while (sceneManager.currentScene != Scenes::GameQuit && !WindowShouldClose());
	}
}