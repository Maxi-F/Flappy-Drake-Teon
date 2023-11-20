#include "UIManager.h"

#include <string>

#include "Objects/Player.h"

namespace flappyBird {
	namespace game {
		namespace uiManager {
			void init() {};
			void update() {};
			void draw() {
				std::string pointsString = "Points: " + std::to_string(player::GetPoints());

				DrawText(
					pointsString.c_str(),
					10,
					10,
					32,
					RED
				);
			};
		}
	}
}
