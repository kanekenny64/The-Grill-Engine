#include "AudioListener.h"

namespace thegrill {
	void AudioListener::on_tick()
	{
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

		glm::vec3 pos = get_entity()->get_transform()->get_position();
	}
}