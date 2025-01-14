#include "AudioListener.h"
#include "Entity.h"
#include "Transform.h"
#include "SoundSystem.h"

namespace thegrill {

	/**
	* @brief Each frame the audio listener updates its position to match the entity it is attached to.
	**/

	void AudioListener::on_tick()
	{
		glm::vec3 position = get_entity()->get_transform()->get_position();
		alListener3f(AL_POSITION, position.x, position.y, position.z);
	}
}