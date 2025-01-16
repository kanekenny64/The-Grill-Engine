#include "Camera.h"
#include "Entity.h"
#include "Core.h"

namespace thegrill
{
	/**
	 * @brief Initializes the camera component.
	 *
	 * This function is called to initialize the camera component. It sets the current camera
	 * in the core to this camera instance.
	 */
	void Camera::on_initialize()
	{
		std::shared_ptr<Camera> self = get_entity()->get_component<Camera>();
		get_core()->add_camera(self);
	}

	void Camera::on_destroy()
	{
		
		get_core()->remove_camera(get_entity()->get_component<Camera>());
	}
}