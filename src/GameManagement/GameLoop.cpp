#include "GameManagement/GameLoop.h"

#include <time.h>
#include "raylib/raylib.h"

#include "GameManagement/Gameplay.h"
#include "GameManagement/Menu.h"
#include "GameManagement/Utilities.h"
#include "GameManagement/SceneManager.h"
#include "GameManagement/SfxManager.h"

namespace flappyBird
{
	static const Vector2 WINDOW_SIZE = { 1280, 720 };

	void Initialize();

	static SceneManager sceneManager;

	void Initialize();
	void Close();
	void GameLoop();

	void RunGame()
	{
		Initialize();
		GameLoop();
		CloseAudioDevice();
		CloseWindow();
	}

	void Initialize()
	{
		InitWindow(static_cast<int>(WINDOW_SIZE.x), static_cast<int>(WINDOW_SIZE.y), "Flappy Drake");
		InitAudioDevice();
		SetExitKey(NULL);
		sceneManager.prevScene = Scenes::GameQuit;
		sfxManager::Init();
		utilities::SetTextures();
		SetRandomSeed(static_cast<unsigned int>(time(nullptr)));
	}

	void Close() 
	{
		sfxManager::Unload();
		utilities::UnloadTextures();
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
			case Scenes::MultiplayerGame:
				game::GamePlayLoop(sceneManager.enteredNewScene, sceneManager.currentScene, true);
				break;
			case Scenes::Menu:
				MenuScene(sceneManager.enteredNewScene, sceneManager.currentScene);
				break;
			case Scenes::Game:
				game::GamePlayLoop(sceneManager.enteredNewScene, sceneManager.currentScene, false);
				break;
			default:
				break;
			}
		} while (sceneManager.currentScene != Scenes::GameQuit && !WindowShouldClose());

		Close();
	}
}