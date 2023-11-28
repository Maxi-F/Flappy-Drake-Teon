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
			BrassDragonSheet,
			TopBackground,
			BackTrees,
			Tree,
			Rules
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
			Texture topBackground;
			Texture firstLineTrees;
			Texture secondLineTrees;
			Texture backTrees;
			Texture brassDragonSheet;
			Texture tree;
			Texture rules;
		};

		void SetTextures();
		Texture GetTexture(TextureIdentifier texture);
		void UnloadTextures();
	}
}