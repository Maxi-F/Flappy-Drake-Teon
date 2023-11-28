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

		void Init();
		void StopAllSounds();
		void PlaySound(SfxName name, bool shouldOverlap);
		void StopSound(SfxName sfxName);
		void PlayMusic(MusicName name);
		void UpdateMusic(MusicName musicName);
		void StopAllMusic();
		void Unload();
	}
}