#ifndef SOUND_SYSTEM_H
#define SOUND_SYSTEM_H

#include <AL/al.h>
#include <AL/alc.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <stdexcept>
#include <vector>
#include <string>

#include "stb_vorbis.c"

namespace thegrill {
	struct SoundSystem
	{
		SoundSystem();
		~SoundSystem();

	private:
		ALCdevice* device;
		ALCcontext* context;
	};
}

#endif // !SOUND_SYSTEM_H