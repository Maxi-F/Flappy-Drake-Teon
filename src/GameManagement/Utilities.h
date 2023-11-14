#pragma once
#include "raylib/raylib.h"
#include "raylib/raymath.h"

#include "TexturesManager.h"

namespace flappyBird
{
	namespace utilities
	{
		struct Rect
		{
			Vector2 position{};
			float height{};
			float width{};
		};
	}
}