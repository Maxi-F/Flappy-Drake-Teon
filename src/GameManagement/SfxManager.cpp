#include "SfxManager.h"

namespace flappyBird 
{
	namespace sfxManager 
	{
		struct SfxWithName
		{
			SfxName name;
			Sound sound;
		};

		struct MusicWithName 
		{
			MusicName name;
			Music music;
			float volume;
		};

		static SfxWithName sfxs[SFX_COUNT];
		static MusicWithName musics[MUSIC_COUNT];


		void Init() 
		{
			SfxWithName redDragonWings = { RED_DRAGON_WINGS, LoadSound("assets/Sounds/redDragonWings.wav") };
			SfxWithName greenDragonWings = { GREEN_DRAGON_WINGS, LoadSound("assets/Sounds/greenDragonWings.wav") };
			SfxWithName click = { CLICK, LoadSound("assets/Sounds/computerClick.mp3") };
			SfxWithName bonk = { COLLISION, LoadSound("assets/Sounds/bonk.wav") };
			SfxWithName drop = { DROP, LoadSound("assets/Sounds/drop.wav") };

			SetSoundVolume(redDragonWings.sound, 0.1f);
			SetSoundVolume(greenDragonWings.sound, 0.1f);
			SetSoundVolume(drop.sound, 0.2f);

			SfxWithName auxSfxs[SFX_COUNT] = 
			{
				redDragonWings,
				greenDragonWings,
				click,
				bonk,
				drop
			};

			for (int i = 0; i < SFX_COUNT; i++) 
			{
				sfxs[i] = auxSfxs[i];
			}

			const float MUSIC_VOLUME = 0.5f;

			MusicWithName gameplay = { GAMEPLAY, LoadMusicStream("assets/Sounds/Epic Chase.mp3"), MUSIC_VOLUME };
			MusicWithName menu = { MENU, LoadMusicStream("assets/Sounds/Savage.mp3"), MUSIC_VOLUME };
			gameplay.music.looping = true;
			menu.music.looping = true;

			MusicWithName auxMusics[MUSIC_COUNT] = { gameplay, menu };

			for (int i = 0; i < MUSIC_COUNT; i++) 
			{
				musics[i] = auxMusics[i];
			}
		};

		void StopAllSounds() 
		{
			for (int i = 0; i < SFX_COUNT; i++) 
			{
				if (IsAudioDeviceReady())
				{
					StopSound(sfxs[i].sound);
				}
			}
		}

		void PlaySound(SfxName sfxName, bool shouldOverlap) 
		{
			for (int i = 0; i < SFX_COUNT; i++) 
			{
				if (IsAudioDeviceReady() && sfxName == sfxs[i].name && (shouldOverlap || !IsSoundPlaying(sfxs[i].sound))) 
				{
					PlaySound(sfxs[i].sound);
				}
			}
		};

		void StopSound(SfxName sfxName) 
		{
			for (int i = 0; i < SFX_COUNT; i++) 
			{
				if (IsAudioDeviceReady() && sfxName == sfxs[i].name) 
				{
					StopSound(sfxs[i].sound);
				}
			}
		}

		void PlayMusic(MusicName musicName) 
		{
			for (int i = 0; i < MUSIC_COUNT; i++) 
			{
				if (IsAudioDeviceReady() && musicName == musics[i].name)
				{
					PlayMusicStream(musics[i].music);
				}
			}
		};

		void UpdateMusic(MusicName musicName) 
		{
			for (int i = 0; i < MUSIC_COUNT; i++) 
			{
				if (IsAudioDeviceReady() && musicName == musics[i].name) 
				{
					SetMusicVolume(musics[i].music, musics[i].volume);
					UpdateMusicStream(musics[i].music);
				}
			}
		}

		void StopAllMusic() 
		{
			for (int i = 0; i < MUSIC_COUNT; i++) 
			{
				if (IsAudioDeviceReady())
				{
					StopMusicStream(musics[i].music);
				}
			}
		}

		void Unload() 
		{
			for (int i = 0; i < SFX_COUNT; i++) 
			{
				UnloadSound(sfxs[i].sound);
			}

			for (int i = 0; i < MUSIC_COUNT; i++)
			{
				UnloadMusicStream(musics[i].music);
			}
		}
	}
}