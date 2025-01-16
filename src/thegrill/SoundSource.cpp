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


    void SoundSource::set_audio(std::shared_ptr<Audio> _audio)
    {
        m_audio = _audio;
        alSourcei(m_Id, AL_BUFFER, m_audio->m_Id);
    }

    void SoundSource::on_tick()
    {
        if (!m_audio)
        {
            throw std::runtime_error("SoundSource Error: No audio set");
            return;
        }

        int state = 0;

        Transform& transform = *get_entity()->get_transform();

		// Set the position of the sound source to the position of the entity
        alSource3f(m_Id, AL_POSITION, transform.get_position().x, transform.get_position().y, transform.get_position().z);
        alGetSourcei(m_Id, AL_SOURCE_STATE, &state);
        if (state != AL_PLAYING && looping) {
            play();
        }
    }


    void SoundSource::play()
    {
        alSourcePlay(m_Id);
    }

    

}
