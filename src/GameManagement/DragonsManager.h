#pragma once
#include "GameManagement/Utilities.h"

namespace flappyBird {
	namespace game {
		namespace dragonsManager {
			extern const int DRAGONS_QUANTITY;

			void Start();
			void Update();
			void Draw();

			Rectangle GetColliderFrom(int index);
			void AddPointToPlayer(int playerIndex, int dragonIndex);
		}
	}
}
