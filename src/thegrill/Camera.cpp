#include "Camera.h"
#include "Entity.h"
#include "Core.h"

namespace thegrill
{
	void Camera::on_initialize()
	{
		std::shared_ptr<Camera> self = get_entity()->get_component<Camera>();
		//Todo: add camera to list of cameras in core then loop through current cameras rendering each one, for now just set the current camera to this one
		//could break if there are multiple cameras, or be weird at least
		get_core()->m_current_cam = self;
	}
}