#include "AudioListener.h"
#include "Entity.h"
#include "Transform.h"

namespace thegrill {
	void AudioListener::on_tick()
	{
		alListener3f(AL_POSITION, get_entity()->get_transform()->get_position().x,
			get_entity()->get_transform()->get_position().y,
				get_entity()->get_transform()->get_position().z);

		
	}
}