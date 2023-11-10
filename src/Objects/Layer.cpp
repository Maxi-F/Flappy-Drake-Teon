#include "Objects/Layer.h"

#include "GameManagement/Utilities.h"

using namespace flappyBird::utilities;

namespace flappyBird
{
	namespace game
	{
		namespace layer
		{
			struct Layer
			{
				Vector2 pos;
				Texture texture;
				int order;

				Rectangle textureSource;
			};

			static Layer ground;
			static Layer leaves;
			static Layer firstLineTrees;
			static Layer secondLineTrees;
			static Layer backLineTrees;

			void SetLayer(Layer& layer, TextureIdentifier id, int layerDepth);
			void UpdateLayer(Layer& layer, float speed);
			void DrawLayer(Layer& layer);

			void SetAllLayers()
			{
				SetLayer(ground, TextureIdentifier::Ground, 4);
				SetLayer(leaves, TextureIdentifier::Leaves, 4);
				SetLayer(firstLineTrees, TextureIdentifier::FirstLineTrees, 3);
				SetLayer(secondLineTrees, TextureIdentifier::SecondLineTrees, 2);
				SetLayer(backLineTrees, TextureIdentifier::BackTrees, 1);
			}

			void UpdateAllLayers(float speed)
			{
				UpdateLayer(ground, speed);
				UpdateLayer(leaves, speed);
				UpdateLayer(firstLineTrees, speed);
				UpdateLayer(secondLineTrees, speed);
				UpdateLayer(backLineTrees, speed);
			}

			void DrawAllLayers()
			{
				DrawLayer(backLineTrees);
				DrawLayer(secondLineTrees);
				DrawLayer(firstLineTrees);
				DrawLayer(ground);
				DrawLayer(leaves);
			}

			void SetLayer(Layer& layer, TextureIdentifier id, int layerDepth)
			{
				layer.order = layerDepth;
				layer.pos = { 0,0 };
				layer.texture = GetTexture(id);
				layer.textureSource.width = static_cast<float>(ground.texture.width);
				layer.textureSource.height = static_cast<float>(ground.texture.height);
			}

			void UpdateLayer(Layer& layer, float speed)
			{
				layer.pos.x -= speed * layer.order * GetFrameTime();
				if (layer.pos.x == -layer.textureSource.width)
					layer.pos.x = static_cast<float>(GetScreenWidth());
			}

			void DrawLayer(Layer& layer)
			{
				static float screenWidth = static_cast<float>(GetScreenWidth());
				static float screenHeight = static_cast<float>(GetScreenHeight());
				Rectangle firstLayerDest = { layer.pos.x, layer.pos.y, screenWidth, screenHeight };
				Rectangle secondLayerDest = { layer.pos.x + layer.textureSource.width, layer.pos.y, screenWidth, screenHeight };
				DrawTexturePro(layer.texture, layer.textureSource, firstLayerDest, { 0,0 }, 0, WHITE);
				DrawTexturePro(layer.texture, layer.textureSource, secondLayerDest, { 0,0 }, 0, WHITE);
			}
		}
	}
}