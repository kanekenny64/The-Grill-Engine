#include "Component.h"
#include <memory>


#include "SoundSystem.h"


namespace thegrill {
	struct Audio;

	struct SoundSource : public Component {
		SoundSource();

		void on_initialize();

		void setAudio(std::shared_ptr<Audio> _audio);

		void on_tick();

		void play();

	private:
		std::shared_ptr<Audio> m_audio;
		ALuint m_Id;
	};

}