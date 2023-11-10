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
			//Player,
			Ground,
			Leaves,
			FirstLineTrees,
			SecondLineTrees,
			BackTrees
		};

		struct AllTextures
		{
			Texture defaultTexture;
			//Texture player;
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