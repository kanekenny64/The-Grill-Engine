#include "Component.h"


namespace thegrill {

	/**
	 * @brief The Audio Listener is a component used to control where audio is heard from.
	 */

	struct AudioListener : public Component {
		AudioListener();

		void on_tick();


	private:
	};

}