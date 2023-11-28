#pragma once
#include "GameManagement/Utilities.h"

namespace flappyBird {
	namespace sfxManager {
		enum SfxName {
			RED_DRAGON_WINGS = 0,
			GREEN_DRAGON_WINGS,
			CLICK,
			COLLISION,
			DROP,
			SFX_COUNT
		};

		enum MusicName {
			GAMEPLAY = 0,
			MENU,
			MUSIC_COUNT
		};

		void init();
		void stopAllSounds();
		void playSound(SfxName name, bool shouldOverlap);
		void stopSound(SfxName sfxName);
		void playMusic(MusicName name);
		void updateMusic(MusicName musicName);
		void stopAllMusic();
	}
}