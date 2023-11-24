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
				utilities::TextureIdentifier id;

				Rectangle textureSource;
			};

			static const int LAYERS_ROLL_QTY = 2;
			static Layer ground[LAYERS_ROLL_QTY];
			static Layer leaves[LAYERS_ROLL_QTY];
			static Layer firstLineTrees[LAYERS_ROLL_QTY];
			static Layer secondLineTrees[LAYERS_ROLL_QTY];
			static Layer backLineTrees[LAYERS_ROLL_QTY];

			/*void SetLayer(Layer& layer, TextureIdentifier id, int layerDepth);
			void UpdateLayer(Layer& layer, float speed);
			void DrawLayer(Layer& layer);*/

			void SetLayer(Layer layer[], TextureIdentifier id, int layerDepth);
			void UpdateLayer(Layer layer[], float speed);
			void DrawLayer(Layer layer[], int yPosition);
			void DrawTopBackground(int yPosition);

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

			void DrawAllLayers(int yPosition)
			{
				DrawTopBackground(yPosition);
				DrawLayer(backLineTrees, yPosition);
				DrawLayer(secondLineTrees, yPosition);
				DrawLayer(firstLineTrees, yPosition);
				DrawLayer(ground, yPosition);
				DrawLayer(leaves, yPosition);
			}

			void SetLayer(Layer layer[], TextureIdentifier id, int layerDepth)
			{
				for (int i = 0; i < LAYERS_ROLL_QTY; i++)
				{
					layer[i].order = layerDepth;
					layer[i].texture = GetTexture(id);
					layer[i].id = id;
					layer[i].textureSource.width = static_cast<float>(layer[i].texture.width);
					layer[i].textureSource.height = static_cast<float>(layer[i].texture.height);
					
					if (id != TextureIdentifier::Leaves) {
						layer[i].pos = { layer[i].textureSource.width * i, 0 };
					}
					else {
						const int LEAVES_Y_POSITION = -300;
						layer[i].pos = { layer[i].textureSource.width * i, LEAVES_Y_POSITION };
					}
				}
			}

			void UpdateLayer(Layer layer[], float speed)
			{
				for (int i = 0; i < LAYERS_ROLL_QTY; i++)
				{
					layer[i].pos.x -= speed * layer[i].order * GetFrameTime();
					if (layer[i].pos.x <= -GetScreenWidth())
						layer[i].pos.x = static_cast<float>(GetScreenWidth());
				}

			}

			void DrawLayer(Layer layer[], int yPosition)
			{
				static float screenWidth = static_cast<float>(GetScreenWidth());
				static float screenHeight = static_cast<float>(GetScreenHeight());
				for (int i = 0; i < LAYERS_ROLL_QTY; i++)
				{
					Rectangle dest = { layer[i].pos.x, layer[i].pos.y + yPosition, screenWidth, screenHeight };
					//Rectangle firstLayerDest = { layer.pos.x, layer.pos.y, screenWidth, screenHeight };
					//Rectangle secondLayerDest = { layer.pos.x + layer.textureSource.width, layer.pos.y, screenWidth, screenHeight };
					DrawTexturePro(layer[i].texture, layer[i].textureSource, dest, { 0,0 }, 0, WHITE);
					//DrawTexturePro(layer[i].texture, layer[i].textureSource, secondLayerDest, { 0,0 }, 0, WHITE);
				}
			}

			void DrawTopBackground(int yPosition) {
				DrawTexture(
					GetTexture(TextureIdentifier::TopBackground),
					0,
					-TOP_BACKGROUND_Y_POSITION + yPosition,
					WHITE
				);
			}
		}
	}
}