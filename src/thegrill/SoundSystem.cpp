#include "SoundSystem.h"


thegrill::SoundSystem::SoundSystem()
{ /*************************************************************************
       * Initialization
       *************************************************************************/
    device = alcOpenDevice(NULL);

    if (!device)
    {
        throw std::runtime_error("Failed to open audio device");
    }

    context = alcCreateContext(device, NULL);

    if (!context)
    {
        alcCloseDevice(device);
        throw std::runtime_error("Failed to create audio context");
    }

    if (!alcMakeContextCurrent(context))
    {
        alcDestroyContext(context);
        alcCloseDevice(device);
        throw std::runtime_error("Failed to make context current");
    }

    alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
}

thegrill::SoundSystem::~SoundSystem()
{
    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device);
}
