#include "Camera.h"
#include "Entity.h"
#include "Core.h"

namespace thegrill
{
	void Camera::on_initialize()
	{
		std::shared_ptr<Camera> self = get_entity()->get_component<Camera>();
		get_core()->m_current_cam = self;
	}
}