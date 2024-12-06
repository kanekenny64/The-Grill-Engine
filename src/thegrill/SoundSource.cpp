#include "SoundSource.h"
#include "Audio.h"


namespace thegrill {


    SoundSource::SoundSource()
    {
    }

    void SoundSource::on_initialize() {
        /*************************************************************************
        * Preparing sound source
        *************************************************************************/
        m_Id = 0;
        alGenSources(1, &m_Id);
       
    }


    void SoundSource::setAudio(std::shared_ptr<Audio> _audio)
    {
        m_audio = _audio;
    }

    void SoundSource::on_tick()
    {
        int state = 0;
            alGetSourcei(m_Id, AL_SOURCE_STATE, &state);
            if (state != AL_PLAYING) {
                play();
            }

            //alSource3f(sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);


    }


    void SoundSource::play()
    {
        /*************************************************************************
         * Play audio
         *************************************************************************/
        alSourcei(m_Id, AL_BUFFER, m_audio->m_Id);
        alSourcePlay(m_audio->m_Id);
    }

    

}
