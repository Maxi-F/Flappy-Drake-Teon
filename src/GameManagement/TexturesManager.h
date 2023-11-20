#pragma once
#include "GameManagement/Utilities.h"

namespace flappyBird
{
	namespace utilities
	{

		// BACKGROUND: https://edermunizz.itch.io/free-pixel-art-forest

		enum class TextureIdentifier
		{
			Default,
			PlayerIdle,
			PlayerFlying,
			PlayerTwoIdle,
			PlayerTwoFlying,
			Ground,
			Leaves,
			FirstLineTrees,
			SecondLineTrees,
			BackTrees
		};

		struct AllTextures
		{
			Texture defaultTexture;
			Texture playerIdle;
			Texture playerFlying;
			Texture playerTwoIdle;
			Texture playerTwoFlying;
			Texture ground;
			Texture leaves;
			Texture firstLineTrees;
			Texture secondLineTrees;
			Texture backTrees;
		};

		void SetTextures();
		Texture GetTexture(TextureIdentifier texture);
	}
}