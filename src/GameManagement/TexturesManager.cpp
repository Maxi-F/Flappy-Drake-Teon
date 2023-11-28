#include "GameManagement/TexturesManager.h"

namespace flappyBird
{
	namespace utilities
	{
		static AllTextures textures;

		void SetTextures()
		{
			textures.defaultTexture = LoadTexture("assets/sprites/DefaultSprite.png");
			textures.playerIdle = LoadTexture("assets/sprites/DragonIdle.png");
			textures.playerFlying = LoadTexture("assets/sprites/DragonFlying.png");
			textures.playerTwoIdle = LoadTexture("assets/sprites/GreenDragonIdle.png");
			textures.playerTwoFlying = LoadTexture("assets/sprites/GreenDragonFlying.png");
			textures.ground = LoadTexture("assets/sprites/ground.png");
			textures.leaves = LoadTexture("assets/sprites/topLeaves.png");
			textures.firstLineTrees = LoadTexture("assets/sprites/firstTrees.png");
			textures.brassDragonSheet = LoadTexture("assets/sprites/MatureBrassDragonSheet.png");
			textures.topBackground = LoadTexture("assets/sprites/topBackground.png");
			textures.secondLineTrees = LoadTexture("assets/sprites/secondTrees.png");
			textures.backTrees = LoadTexture("assets/sprites/backTrees.png");
			textures.tree = LoadTexture("assets/sprites/tree.png");
			textures.rules = LoadTexture("assets/sprites/rules.png");
		}
		Texture GetTexture(TextureIdentifier texture)
		{
			switch (texture)
			{
			case TextureIdentifier::PlayerIdle:
				return textures.playerIdle;
				break;
			case TextureIdentifier::PlayerFlying:
				return textures.playerFlying;
				break;
			case TextureIdentifier::Ground:
				return textures.ground;
				break;
			case TextureIdentifier::Leaves:
				return textures.leaves;
				break;
			case TextureIdentifier::FirstLineTrees:
				return textures.firstLineTrees;
				break;
			case TextureIdentifier::SecondLineTrees:
				return textures.secondLineTrees;
				break;
			case TextureIdentifier::BackTrees:
				return textures.backTrees;
				break;
			case TextureIdentifier::PlayerTwoIdle:
				return textures.playerTwoIdle;
				break;
			case TextureIdentifier::PlayerTwoFlying:
				return textures.playerTwoFlying;
				break;
			case TextureIdentifier::Tree:
				return textures.tree;
				break;
			case TextureIdentifier::Rules:
				return textures.rules;
				break;
			case TextureIdentifier::TopBackground:
				return textures.topBackground;
				break;
			case TextureIdentifier::BrassDragonSheet:
				return textures.brassDragonSheet;
				break;
			default:
				return textures.defaultTexture;
				break;
			}
		}

		void UnloadTextures() {
			UnloadTexture(textures.defaultTexture);
			UnloadTexture(textures.playerIdle);
			UnloadTexture(textures.playerFlying);
			UnloadTexture(textures.playerTwoIdle);
			UnloadTexture(textures.playerTwoFlying);
			UnloadTexture(textures.ground);
			UnloadTexture(textures.leaves);
			UnloadTexture(textures.firstLineTrees);
			UnloadTexture(textures.topBackground);
			UnloadTexture(textures.brassDragonSheet);
			UnloadTexture(textures.secondLineTrees);
			UnloadTexture(textures.backTrees);
			UnloadTexture(textures.tree);
			UnloadTexture(textures.rules);
		}
	}
}
