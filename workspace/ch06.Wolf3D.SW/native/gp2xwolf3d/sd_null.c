#include "wl_def.h"

boolean AdLibPresent, SoundBlasterPresent;

SDMode SoundMode;
//SDMode MusicMode;
SDSMode DigiMode;

static boolean SD_Started;

extern void jni_printf(char *format, ...);
extern void jni_start_sound (int idx);
extern void jni_start_music (int idx);

void SD_SetDigiDevice(SDSMode mode)
{
}

///////////////////////////////////////////////////////////////////////////
//
//	SD_SetSoundMode() - Sets which sound hardware to use for sound effects
//
///////////////////////////////////////////////////////////////////////////
boolean SD_SetSoundMode(SDMode mode)
{
	//jni_printf("SD_SetSoundMode %d", mode);
	return true;
}

///////////////////////////////////////////////////////////////////////////
//
//	SD_SetMusicMode() - sets the device to use for background music
//
///////////////////////////////////////////////////////////////////////////
boolean SD_SetMusicMode(SMMode mode)
{
	//jni_printf("SD_SetMusicMode %d", mode);
	return true;
}

///////////////////////////////////////////////////////////////////////////
//
//	SD_Startup() - starts up the Sound Mgr
//
///////////////////////////////////////////////////////////////////////////
void SD_Startup()
{
	if (SD_Started)
		return;
	
	//jni_printf("SD_Startup");
	InitDigiMap();
}

///////////////////////////////////////////////////////////////////////////
//
//	SD_Shutdown() - shuts down the Sound Mgr
//
///////////////////////////////////////////////////////////////////////////
void SD_Shutdown()
{
	if (!SD_Started)
		return;

	SD_Started = false;
}

///////////////////////////////////////////////////////////////////////////
//
//	SD_PlaySound() - plays the specified sound on the appropriate hardware
//
///////////////////////////////////////////////////////////////////////////
boolean SD_PlaySoundWL6(soundnamesWL6 sound)
{
	//jni_printf("SD_PlaySound WL6 %d", sound);
	jni_start_sound (sound);
	return true;
}

boolean SD_PlaySoundSOD(soundnamesSOD sound)
{
	//jni_printf("SD_PlaySound SOD %d", sound);
	jni_start_sound (sound);
	return true;
}

///////////////////////////////////////////////////////////////////////////
//
//	SD_SoundPlaying() - returns the sound number that's playing, or 0 if
//		no sound is playing
//
///////////////////////////////////////////////////////////////////////////
word SD_SoundPlaying()
{
	return false;
}

///////////////////////////////////////////////////////////////////////////
//
//	SD_StopSound() - if a sound is playing, stops it
//
///////////////////////////////////////////////////////////////////////////
void SD_StopSound()
{
}

///////////////////////////////////////////////////////////////////////////
//
//	SD_WaitSoundDone() - waits until the current sound is done playing
//
///////////////////////////////////////////////////////////////////////////
void SD_WaitSoundDone()
{
/* TODO: should also "work" when sound is disabled... */
	while (SD_SoundPlaying())
		;
}

///////////////////////////////////////////////////////////////////////////
//
//	SD_MusicOn() - turns on the sequencer
//
///////////////////////////////////////////////////////////////////////////
void SD_MusicOn()
{
}

///////////////////////////////////////////////////////////////////////////
//
//	SD_MusicOff() - turns off the sequencer and any playing notes
//
///////////////////////////////////////////////////////////////////////////
void SD_MusicOff()
{
	//jni_printf("SD_MusicOff");
}

///////////////////////////////////////////////////////////////////////////
//
//	SD_StartMusic() - starts playing the music pointed to
//
///////////////////////////////////////////////////////////////////////////
void SD_StartMusic(int music)
{
	//jni_printf("SD_StartMusic %d", music);
	jni_start_music(music);
	SD_MusicOff();
}

void PlaySoundLocGlobal(word s, int id, fixed gx,fixed gy)
{
	//SD_PlaySound(s);
	if (w0 == true || w1 == true){
		if (SD_PlaySoundWL6(s)) {
		}
	} else {
		if (SD_PlaySoundSOD(s)) {
		}
	}

}

void UpdateSoundLoc(fixed x, fixed y, int angle)
{
}

