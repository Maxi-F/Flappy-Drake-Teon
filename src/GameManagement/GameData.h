#pragma once
#include "Objects/Player.h"
#include "Objects/Obstacle.h"

namespace flappyBird
{
	namespace game
	{
		struct GameData
		{
			player::Player player;
			obstacle::Obstacle obstacle;
		};
	}
}