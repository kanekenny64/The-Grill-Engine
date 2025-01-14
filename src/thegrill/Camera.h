#include "Component.h"

namespace thegrill
{
	/**
	 * @brief The BoxCollider class is used to control the position of the camera to be used in rendering pipeline.
	 */

	struct Camera : public Component {
		void on_initialize();
	};
}