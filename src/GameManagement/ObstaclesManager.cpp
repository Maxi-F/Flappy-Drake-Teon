#include "GameManagement/ObstaclesManager.h"

namespace flappyBird
{
	namespace game
	{
		namespace obstaclesManager
		{
			static obstacle::Obstacle obstacles[OBSTACLES_QTY];

			static float offset = 0;
			void Start()
			{
				offset = static_cast<float>(GetScreenWidth()) / 2;

				for (int i = 0; i < OBSTACLES_QTY; i++)
				{
					obstacle::Start(obstacles[i], offset * i);
				}
			}

			void Update()
			{
				for (int i = 0; i < OBSTACLES_QTY; i++)
				{
					obstacle::Update(obstacles[i]);
				}
			}

			void Draw()
			{
				for (int i = 0; i < OBSTACLES_QTY; i++)
				{
					obstacle::Draw(obstacles[i]);
				}
			}

			void ResetObstacles()
			{
				Start();
			}

			void addPointToPlayer(player::Player &player, int obstacleIndex) {
				if (player.pos.x >= obstacles[obstacleIndex].pos.x && !obstacles[obstacleIndex].countedPoint) {
					player.points++;
					obstacles[obstacleIndex].countedPoint = true;
				}
			}

			Rectangle GetObstacleUpperCollider(int obstacleIndex)
			{
				return obstacle::GetUpperCollider(obstacles[obstacleIndex]);
			}
			Rectangle GetObstacleLowerCollider(int obstacleIndex)
			{
				return obstacle::GetLowerCollider(obstacles[obstacleIndex]);
			}
		}
	}
}
