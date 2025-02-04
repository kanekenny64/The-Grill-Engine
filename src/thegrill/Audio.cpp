#include "Audio.h"
#include "stb_vorbis.c"

namespace thegrill {
    void Audio::onLoad()
    {

         /*************************************************************************
      * Preparing buffer
      *************************************************************************/

        load_ogg(getPath() + ".ogg", bufferData, format, freq);

        m_Id = 0;
        alGenBuffers(1, &m_Id);

        alBufferData(m_Id, format, &bufferData.at(0),
            static_cast<ALsizei>(bufferData.size()), freq);
    }


    Audio::~Audio()
    {
        alDeleteBuffers(1, &m_Id);
    }


    void Audio::load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer, ALenum& _format, ALsizei& _freq)
	{
        int channels = 0;
        int sampleRate = 0;
        short* output = NULL;

		// Load the OGG file into memory
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

	void Audio::onUnload()
	{
		alDeleteBuffers(1, &m_Id);
	}
    
}