#include "SoundSource.h"
#include "Audio.h"
#include "Entity.h"
#include "Transform.h"


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
        alSourcei(m_Id, AL_BUFFER, m_audio->m_Id);
    }

    void SoundSource::on_tick()
    {
        int state = 0;
        alSource3f(m_Id, AL_POSITION, get_entity()->get_transform()->get_position().x,
            get_entity()->get_transform()->get_position().y,
                get_entity()->get_transform()->get_position().z);
        alGetSourcei(m_Id, AL_SOURCE_STATE, &state);
        if (state != AL_PLAYING) {
            play();
        }

            
        alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

    }


    void SoundSource::play()
    {
        /*************************************************************************
         * Play audio
         *************************************************************************/
        
        alSourcePlay(m_audio->m_Id);
    }

    

}
