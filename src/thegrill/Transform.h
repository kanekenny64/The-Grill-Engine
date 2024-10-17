#include "Component.h"
#include <glm/glm.hpp>


namespace thegrill {
	struct Transform : Component
	{
		glm::vec3 m_position;
		glm::vec3 m_rotation;
		glm::vec3 m_scale = { 1.0,1.0,1.0 };
	};
}