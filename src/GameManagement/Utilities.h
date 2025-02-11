#pragma once
/*
	In this codebase, including "GameManagement/Utilities.h" already
	includes raylib, raymath and the texturesManager.
*/
#include "raylib/raylib.h"
#include "raylib/raymath.h"

#include "TexturesManager.h"

namespace flappyBird
{
	namespace utilities
	{
		extern const int TOP_BACKGROUND_Y_POSITION;
		struct Rect
		{
			Vector2 position{};
			float height{};
			float width{};
		};
	}
}