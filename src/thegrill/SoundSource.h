#include "Component.h"
#include <memory>
#include "SoundSystem.h"


namespace thegrill {
	struct Audio;

	struct SoundSource : public Component {
		SoundSource();

		void on_initialize();

		void set_audio(std::shared_ptr<Audio> _audio);

		void on_tick();

		void play();

		void set_looping(bool _looping) {
			looping = _looping;
		}

	private:
		std::shared_ptr<Audio> m_audio;
		ALuint m_Id;

		bool looping = false;

		float pitch = 1;
	};

}