#include "Component.h"
#include "SoundSystem.h"

namespace thegrill {

	struct AudioListener : public Component {
		AudioListener();

		void on_tick();


	private:
	};

}