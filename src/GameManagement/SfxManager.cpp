#include "SfxManager.h"

namespace flappyBird {
	namespace sfxManager {
		struct SfxWithName {
			SfxName name;
			Sound sound;
		};

		struct MusicWithName {
			MusicName name;
			Music music;
			float volume;
		};

		static SfxWithName sfxs[SFX_COUNT];
		static MusicWithName musics[MUSIC_COUNT];


		void init() {
			SfxWithName redDragonWings = { RED_DRAGON_WINGS, LoadSound("assets/Sounds/redDragonWings.wav") };
			SfxWithName greenDragonWings = { GREEN_DRAGON_WINGS, LoadSound("assets/Sounds/greenDragonWings.wav") };
			SfxWithName click = { CLICK, LoadSound("assets/Sounds/computerClick.mp3") };
			SfxWithName bonk = { COLLISION, LoadSound("assets/Sounds/bonk.wav") };
			SfxWithName drop = { DROP, LoadSound("assets/Sounds/drop.wav") };

			SfxWithName auxSfxs[SFX_COUNT] = {
				redDragonWings
			};

			for (int i = 0; i < SFX_COUNT; i++) {
				sfxs[i] = auxSfxs[i];
			}

			const float MUSIC_VOLUME = 0.3f;

			MusicWithName gameplay = { GAMEPLAY, LoadMusicStream("assets/Sounds/Epic Chase.mp3"), MUSIC_VOLUME };
			MusicWithName menu = { MENU, LoadMusicStream("assets/Sounds/Savage.mp3"), MUSIC_VOLUME };
			gameplay.music.looping = true;
			menu.music.looping = true;

			MusicWithName auxMusics[MUSIC_COUNT] = { gameplay, menu };

			for (int i = 0; i < MUSIC_COUNT; i++) {
				musics[i] = auxMusics[i];
			}
		};

		void stopAllSounds() {
			for (int i = 0; i < SFX_COUNT; i++) {
				if (IsAudioDeviceReady()) {
					StopSound(sfxs[i].sound);
				}
			}
		}

		void playSound(SfxName sfxName, bool shouldOverlap) {
			for (int i = 0; i < SFX_COUNT; i++) {
				if (IsAudioDeviceReady() && sfxName == sfxs[i].name && (shouldOverlap || !IsSoundPlaying(sfxs[i].sound))) {
					PlaySound(sfxs[i].sound);
				}
			}
		};

		void stopSound(SfxName sfxName) {
			for (int i = 0; i < SFX_COUNT; i++) {
				if (IsAudioDeviceReady() && sfxName == sfxs[i].name) {
					StopSound(sfxs[i].sound);
				}
			}
		}

		void playMusic(MusicName musicName) {
			for (int i = 0; i < MUSIC_COUNT; i++) {
				if (IsAudioDeviceReady() && musicName == musics[i].name) {
					PlayMusicStream(musics[i].music);
				}
			}
		};

		void updateMusic(MusicName musicName) {
			for (int i = 0; i < MUSIC_COUNT; i++) {
				if (IsAudioDeviceReady() && musicName == musics[i].name) {
					SetMusicVolume(musics[i].music, musics[i].volume);
					UpdateMusicStream(musics[i].music);
				}
			}
		}

		void stopAllMusic() {
			for (int i = 0; i < MUSIC_COUNT; i++) {
				if (IsAudioDeviceReady()) {
					StopMusicStream(musics[i].music);
				}
			}
		}
	}
}