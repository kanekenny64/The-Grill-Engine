#include "SoundSource.h"



namespace thegrill {
    SoundSource::SoundSource()
    {
       
        //alListener3f(AL_VELOCITY, 0.0f, 0.0f, 0.0f);

          /*************************************************************************
       * Preparing buffer
       *************************************************************************/

        load_ogg("../dixie_horn.ogg", bufferData, format, freq);

        ALuint bufferId = 0;
        alGenBuffers(1, &bufferId);

        alBufferData(bufferId, format, &bufferData.at(0),
            static_cast<ALsizei>(bufferData.size()), freq);

        /*************************************************************************
         * Preparing sound source
         *************************************************************************/
        ALuint sourceId = 0;
        alGenSources(1, &sourceId);

        alSourcei(sourceId, AL_BUFFER, bufferId);
        //alSource3f(sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
        //alSourcef(sourceId, AL_PITCH, 10);
        //alSourcef(sourceId, AL_GAIN, vol);

        /*************************************************************************
         * Play audio
         *************************************************************************/
        alSourcePlay(sourceId);

        /*************************************************************************
         * Tick
         *************************************************************************/

        while (true)
        {
            int state = 0;
            alGetSourcei(sourceId, AL_SOURCE_STATE, &state);
            if (state != AL_PLAYING) break;

            //alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

#ifdef _WIN32
            Sleep(10);
#else
            usleep(100 * 1000);
#endif
        }

        /*************************************************************************
         * Cleanup
         *************************************************************************/
        alDeleteSources(1, &sourceId);
        alDeleteBuffers(1, &bufferId);
        alcMakeContextCurrent(NULL);
        
    }

    void SoundSource::load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, ALenum& _format, ALsizei& _freq)
    {
        int channels = 0;
        int sampleRate = 0;
        short* output = NULL;

        size_t samples = stb_vorbis_decode_filename(_path.c_str(),
            &channels, &sampleRate, &output);

        if (samples == -1)
        {
            throw std::runtime_error("Failed to open file '" + _path + "' for decoding");
        }

        // Record the format required by OpenAL
        if (channels < 2)
        {
            _format = AL_FORMAT_MONO16;
        }
        else
        {
            _format = AL_FORMAT_STEREO16;
        }

        // Copy (# samples) * (1 or 2 channels) * (16 bits == 2 bytes == short)
        _buffer.resize(samples * channels * sizeof(short));
        memcpy(&_buffer.at(0), output, _buffer.size());

        // Record the sample rate required by OpenAL
        _freq = sampleRate;

        // Clean up the read data
        free(output);
    }

}
